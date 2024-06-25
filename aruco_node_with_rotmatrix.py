"""
This node locates Aruco AR markers in images and publishes poses.

Subscriptions:
   /camera/color/image_raw (sensor_msgs.msg.Image)
   /camera/color/camera_info (sensor_msgs.msg.CameraInfo)

Published Topics:

    /aruco_markers (ros2_aruco_interfaces.msg.ArucoMarkers)
       Provides an array of all poses along with the corresponding
       marker ids.
    /robot_poses_1 (geometry_msgs.msg.PoseArray)
        Pose of detected markers with ID 1
    /robot_poses_2 (geometry_msgs.msg.PoseArray)
        Pose of detected markers with ID 2    
    /marked_video (sensor_msgs.msg.Image)
        Video with detected markers highlighted and IDs shown 
    /unmarked_video_url (std_msgs.msg)
        Encoded string URL of unmarked video to be shown in web used together with ROSLIB library
    /video_url (std_msgs.msg)
        Encoded string URL of marked video to be shown in web used together with ROSLIB library

Parameters:
    marker_size - size of the markers in meters (default .0625)
    aruco_dictionary_id - dictionary that was used to generate markers
                          (default DICT_5X5_250)
    image_topic - image topic to subscribe to (default /camera/image_raw)
    camera_info_topic - camera info topic to subscribe to
                         (default /camera/camera_info)

Author: Edwin Ooi Yong Qing
Credits: Nathan Sprague
pip install opencv-contrib-python==4.6.0.66
"""
import base64
import rclpy
import rclpy.node
from rclpy.qos import qos_profile_sensor_data
from cv_bridge import CvBridge
import numpy as np
import cv2
# import tf_transformations
from std_msgs.msg import String
from sensor_msgs.msg import CameraInfo
from sensor_msgs.msg import Image
from geometry_msgs.msg import PoseArray, Pose
from ros2_aruco_interfaces.msg import ArucoMarkers
from rcl_interfaces.msg import ParameterDescriptor, ParameterType
from scipy.spatial.transform import Rotation as R

class ArucoNode(rclpy.node.Node):
    def __init__(self):
        super().__init__("aruco_node")

        # Declare and read parameters
        self.declare_parameter(
            name="marker_size",
            value=0.07,
            descriptor=ParameterDescriptor(
                type=ParameterType.PARAMETER_DOUBLE,
                description="Size of the markers in meters.",
            ),
        )

        self.declare_parameter(
            name="aruco_dictionary_id",
            value="DICT_5X5_100",
            descriptor=ParameterDescriptor(
                type=ParameterType.PARAMETER_STRING,
                description="Dictionary that was used to generate markers.",
            ),
        )

        self.declare_parameter(
            name="image_topic",
            value="/camera/color/image_raw",
            descriptor=ParameterDescriptor(
                type=ParameterType.PARAMETER_STRING,
                description="Image topic to subscribe to.",
            ),
        )

        self.declare_parameter(
            name="camera_info_topic",
            value="/camera/color/camera_info",
            descriptor=ParameterDescriptor(
                type=ParameterType.PARAMETER_STRING,
                description="Camera info topic to subscribe to.",
            ),
        )

        self.declare_parameter(
            name="gTc_matrix",
            value= [
                    1.0, 0.0, 0.0, 1.35, 
                    0.0, -1.0, 0.0, 0.95, 
                    0.0, 0.0, -1.0, 2.7, 
                    0.0, 0.0, 0.0, 1.0
                    ],   
            descriptor=ParameterDescriptor(
                type=ParameterType.PARAMETER_DOUBLE_ARRAY,
                description="4x4 Homogeneous Transformation Matrix from Global to Camera.",
            ),
        )

        self.declare_parameter(
            name="robot_center_offset",
            value=[0.084, -0.084, 0.0, 1.0] ,          
            descriptor=ParameterDescriptor(
                type=ParameterType.PARAMETER_DOUBLE_ARRAY,
                description="4x4 Homogeneous Transformation Matrix from Global to Camera.",
            ),
        )

        self.declare_parameter(
            name="camera_frame",
            value="",
            descriptor=ParameterDescriptor(
                type=ParameterType.PARAMETER_STRING,
                description="Camera optical frame to use.",
            ),
        )

        self.marker_size = (
            self.get_parameter("marker_size").get_parameter_value().double_value
        )
        self.get_logger().info(f"Marker size: {self.marker_size}")

        dictionary_id_name = (
            self.get_parameter("aruco_dictionary_id").get_parameter_value().string_value
        )
        self.get_logger().info(f"Marker type: {dictionary_id_name}")

        image_topic = (
            self.get_parameter("image_topic").get_parameter_value().string_value
        )
        self.get_logger().info(f"Image topic: {image_topic}")

        info_topic = (
            self.get_parameter("camera_info_topic").get_parameter_value().string_value
        )
        self.get_logger().info(f"Image info topic: {info_topic}")

        self.camera_frame = (
            self.get_parameter("camera_frame").get_parameter_value().string_value
        )

        self.gTc_matrix = (
            self.get_parameter("gTc_matrix").get_parameter_value().double_array_value
        )
        self.get_logger().info(f"gTc_matrix: {self.gTc_matrix}")

        self.robot_center_offset = (
            self.get_parameter("robot_center_offset").get_parameter_value().double_array_value
        )
        self.get_logger().info(f"Robot Center Offset: {self.robot_center_offset}")

        # Make sure we have a valid dictionary id:
        try:
            dictionary_id = cv2.aruco.__getattribute__(dictionary_id_name)
            if type(dictionary_id) != type(cv2.aruco.DICT_5X5_100):
                raise AttributeError
        except AttributeError:
            self.get_logger().error(
                "bad aruco_dictionary_id: {}".format(dictionary_id_name)
            )
            options = "\n".join([s for s in dir(cv2.aruco) if s.startswith("DICT")])
            self.get_logger().error("valid options: {}".format(options))

        # Set up subscriptions
        self.info_sub = self.create_subscription(
            CameraInfo, info_topic, self.info_callback, qos_profile_sensor_data
        )

        self.create_subscription(
            Image, image_topic, self.image_callback, qos_profile_sensor_data
        )

        # Set up publishers
        self.markers_pub = self.create_publisher(ArucoMarkers, "aruco_markers", 10)
        self.robot_poses1_pub = self.create_publisher(PoseArray, "robot_poses_1", 10)
        self.robot_poses2_pub = self.create_publisher(PoseArray, "robot_poses_2", 10)
        self.marked_video_pub = self.create_publisher(Image, "marked_video", 10)
        self.video_url_pub = self.create_publisher(String, "video_url", 10)
        self.unmarked_video_url_pub = self.create_publisher(String, "unmarked_video_url", 10)

        # Set up fields for camera parameters
        self.info_msg = None
        self.intrinsic_mat = None
        self.distortion = None

        # OpenCV version 4.6.0
        # pip install opencv-contrib-python==4.6.0.66
        self.aruco_dictionary = cv2.aruco.Dictionary_get(dictionary_id)
        # self.aruco_dictionary = cv2.aruco.Dictionary_create(dictionary_id)
        self.aruco_parameters = cv2.aruco.DetectorParameters_create()
        self.bridge = CvBridge()
    
    def rot2homo(self, rotation_matrix, translation_vector):
        homogeneous_matrix = np.eye(4)
        homogeneous_matrix[:3, :3] = rotation_matrix
        homogeneous_matrix[:3, 3] = translation_vector
        return homogeneous_matrix
    
    def homo2rot(self, homogeneous_matrix):
        rotation_matrix = homogeneous_matrix[:3, :3]
        return rotation_matrix

    def info_callback(self, info_msg):
        self.info_msg = info_msg
        self.intrinsic_mat = np.reshape(np.array(self.info_msg.k), (3, 3))
        self.distortion = np.array(self.info_msg.d)
        # Assume that camera parameters will remain the same...
        self.destroy_subscription(self.info_sub)

    def image_callback(self, img_msg):
        if self.info_msg is None:
            self.get_logger().warn("No camera info has been received!")
            return

        markers = ArucoMarkers()
        robot_poses1 = PoseArray()
        robot_poses2 = PoseArray()
        video_url = String()
        unmarked_video_url = String()

        cv_image = self.bridge.imgmsg_to_cv2(img_msg, desired_encoding="bgr8")
        _, buffer = cv2.imencode('.jpg', cv_image)
        unmarked_video_url.data= base64.b64encode(buffer).decode('utf-8')
        self.unmarked_video_url_pub.publish(unmarked_video_url) 

        if self.camera_frame == "":
            markers.header.frame_id = self.info_msg.header.frame_id
            robot_poses1.header.frame_id = self.info_msg.header.frame_id
            robot_poses2.header.frame_id = self.info_msg.header.frame_id
        else:
            markers.header.frame_id = self.camera_frame
            robot_poses1.header.frame_id = self.camera_frame
            robot_poses2.header.frame_id = self.camera_frame

        markers.header.stamp = img_msg.header.stamp
        robot_poses1.header.stamp = img_msg.header.stamp
        robot_poses2.header.stamp = img_msg.header.stamp

        corners, marker_ids, rejected = cv2.aruco.detectMarkers(
            cv_image, self.aruco_dictionary, parameters=self.aruco_parameters
        )

        if marker_ids is not None:
            if cv2.__version__ > "4.0.0":
                rvecs, tvecs, _ = cv2.aruco.estimatePoseSingleMarkers(
                    corners, self.marker_size, self.intrinsic_mat, self.distortion
                )
            else:
                rvecs, tvecs = cv2.aruco.estimatePoseSingleMarkers(
                    corners, self.marker_size, self.intrinsic_mat, self.distortion
                )
            for i, marker_id in enumerate(marker_ids):

                # extract the marker corners (which are always returned in
		        # top-left, top-right, bottom-right, and bottom-left order)
                markerCorner = corners[i].reshape((4, 2))
                (topLeft, topRight, bottomRight, bottomLeft) = markerCorner
                
                # convert each of the (x, y)-coordinate pairs to integers
                topRight = (int(topRight[0]), int(topRight[1]))
                bottomRight = (int(bottomRight[0]), int(bottomRight[1]))
                bottomLeft = (int(bottomLeft[0]), int(bottomLeft[1]))
                topLeft = (int(topLeft[0]), int(topLeft[1]))

                # draw the bounding box of the ArUCo detection
                cv2.line(cv_image, topLeft, topRight, (0, 255, 0), 2)
                cv2.line(cv_image, topRight, bottomRight, (0, 255, 0), 2)
                cv2.line(cv_image, bottomRight, bottomLeft, (0, 255, 0), 2)
                cv2.line(cv_image, bottomLeft, topLeft, (0, 255, 0), 2)  

                # compute and draw the center (x, y)-coordinates of the ArUco
                # marker
                cX = int((topLeft[0] + bottomRight[0]) / 2.0)
                cY = int((topLeft[1] + bottomRight[1]) / 2.0)
                cv2.circle(cv_image, (cX, cY), 2, (0, 0, 255), -1)
                
                # draw the ArUco marker ID on the image
                cv2.putText(cv_image, str(marker_id[0]),
                    (topLeft[0], topLeft[1] - 15), cv2.FONT_HERSHEY_SIMPLEX,
                    0.5, (0, 0, 255), 2)
                print("[INFO] ArUco marker ID: {}".format(marker_id))                             

                # rvec to rmat
                # rot_matrix = np.eye(4)                                            # Original method
                # rot_matrix[0:3, 0:3] = cv2.Rodrigues(np.array(rvecs[i][0]))[0]    # Original method
                
                # rmat to quat
                # quat = tf_transformations.quaternion_from_matrix(rot_matrix)      # Original method
                
                # Rotation Conversion
                cTm_rvecs = R.from_rotvec(np.array(rvecs[i][0]))
                cTm_rot_matrix = cTm_rvecs.as_matrix()                
                # quat = cTm_rvecs.as_quat()
                # euler_angles_radians = cTm_rvecs.as_euler('zxy', degrees=True)

                # Calculating Homogeneous Matrix
                gTc_homo_matrix = np.reshape(np.array(self.gTc_matrix),(4,4))
                cTm_homo_matrix = self.rot2homo(cTm_rot_matrix, tvecs[i][0])
                gTm_homo_matrix = np.dot(gTc_homo_matrix, np.array(cTm_homo_matrix))
                gTm_rot_matrix = self.homo2rot(gTm_homo_matrix)
                r = R.from_matrix(gTm_rot_matrix)
                gTm_quat = r.as_quat()
                position_global_meter = np.dot(gTm_homo_matrix, np.array(self.robot_center_offset))
                position_global = position_global_meter * 1000
                
                # Display position in logger
                self.get_logger().info(f"Position [x,y,z]: {position_global}")

                # Display rot_matrix in logger
                for j, value in enumerate(gTm_homo_matrix):
                    self.get_logger().info(f"Rotation Matrix Row {j}: {value}")

                # Display euler angle in logger
                # self.get_logger().info(f"Element {i}: {rvecs[i][0]}")
                # self.get_logger().info(f"Marker ID {marker_id} Yaw   : {euler_angles_radians[0]}")
                # self.get_logger().info(f"Marker ID {marker_id} Roll  : {euler_angles_radians[1]}")
                # self.get_logger().info(f"Marker ID {marker_id} Pitch : {euler_angles_radians[2]}")

                # Translation data
                pose = Pose()
                # pose.position.x = tvecs[i][0][0]
                # pose.position.y = tvecs[i][0][1]
                # pose.position.z = tvecs[i][0][2]
                pose.position.x = position_global[0]
                pose.position.y = position_global[1]
                pose.position.z = position_global[2]

                # Rotation data
                pose.orientation.x = gTm_quat[0]
                pose.orientation.y = gTm_quat[1]
                pose.orientation.z = gTm_quat[2]
                pose.orientation.w = gTm_quat[3]

                # Add data to msg
                if (marker_id[0] == 1):         # Robot 1
                    robot_poses1.poses.append(pose)
                    self.robot_poses1_pub.publish(robot_poses1)
                elif (marker_id[0] == 2):       # Robot 2
                    robot_poses2.poses.append(pose)
                    self.robot_poses2_pub.publish(robot_poses2)

                markers.poses.append(pose)
                markers.marker_ids.append(marker_id[0])
                self.markers_pub.publish(markers)

                # for a, value in enumerate(gTm_rot_matrix):
                #     #Check if the matrix is 3x3 or 4x4
                #     # if len(gTm_rot_matrix) == 3: 
                #     #     for b in [0,1,2]:
                #     #         markers.rot_mat.append(gTm_rot_matrix[a][b])
                #     # if len(gTm_rot_matrix) == 4: 
                #     #     for b in [0,1,2,3]:
                #     #         markers.rot_mat.append(gTm_rot_matrix[a][b])
                #     for b in [0,1,2]:
                #         markers.rot_mat.append(gTm_rot_matrix[a][b])

        marked_video = self.bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")
        self.marked_video_pub.publish(marked_video)

        # Publish video url
        _, buffer = cv2.imencode('.jpg', cv_image)
        video_url.data= base64.b64encode(buffer).decode('utf-8')
        self.video_url_pub.publish(video_url)
       


def main():
    rclpy.init()
    node = ArucoNode()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
