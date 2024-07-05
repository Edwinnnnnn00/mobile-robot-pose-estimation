#!//usr/bin/bash
source /home/edwinooi/Desktop/foxy_ws/install/setup.bash

# Launch the RealSense camera node
echo "Launching RealSense camera node..."
ros2 launch realsense2_camera rs_launch.py pointcloud.enable:=false align_depth.enable:=false &
CAMERA_PID=$!
sleep 3  # Wait for the camera node to start

# Start RViz2 with the specified configuration
# echo "Starting RViz2..."
# rviz2 --display-config /home/orin_nano/Desktop/foxy_ws/src/turtlebot3_simulations/realsense-ros-4.51.1/realsense2_camera/launch/default.rviz &
# RVIZ_PID=$!
# sleep 5  # Wait for RViz2 to start

# Run the image view node to visualize the camera feed
echo "Running image view node..."
ros2 run image_view image_view --ros-args --remap image:=/camera/color/image_raw &
IMAGE_VIEW_PID=$!
sleep 3  # Wait for the image view node to start

# Launch the ArUco marker recognition node
echo "Launching ArUco marker recognition node..."
ros2 launch ros2_aruco aruco_recognition_with_rotmatrix.launch.py &
ARUCO_PID=$!
sleep 10  # Wait for the ArUco marker recognition node to start

# Echo the /aruco_markers topic
# echo "Echoing /aruco_markers topic..."
# ros2 topic echo /aruco_markers &
# ECHO_PID=$!

# Launch the rosbridge server
# source /home/edwinooi/Desktop/web_src/install/setup.bash
# ros2 launch rosbridge_server rosbridge_websocket_launch.xml 
# ros2 run image_view image_view --ros-args --remap image:=/marked_video


# Wait for all background processes
wait $CAMERA_PID $IMAGE_VIEW_PID $ARUCO_PID
