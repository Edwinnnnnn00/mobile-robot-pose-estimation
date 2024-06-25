# mobile-robot-pose-estimation
An algorithm that detects Aruco markers in the video and calculates its poses in global frame.

Subscriptions:

   /camera/color/image_raw (sensor_msgs.msg.Image)
      Video topic from camera
   /camera/color/camera_info (sensor_msgs.msg.CameraInfo)
      Camera info topic of camera

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
    gTc_matrix - transformation matrix from global fram to camera frame
    robot_center_offset - center of robot in marker's frame
