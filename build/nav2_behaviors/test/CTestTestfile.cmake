# CMake generated Testfile for 
# Source directory: /home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_behaviors/test
# Build directory: /home/edwinooi/Desktop/foxy_ws/build/nav2_behaviors/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_behaviors "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/home/edwinooi/Desktop/foxy_ws/build/nav2_behaviors/test_results/nav2_behaviors/test_behaviors.gtest.xml" "--package-name" "nav2_behaviors" "--output-file" "/home/edwinooi/Desktop/foxy_ws/build/nav2_behaviors/ament_cmake_gtest/test_behaviors.txt" "--command" "/home/edwinooi/Desktop/foxy_ws/build/nav2_behaviors/test/test_behaviors" "--gtest_output=xml:/home/edwinooi/Desktop/foxy_ws/build/nav2_behaviors/test_results/nav2_behaviors/test_behaviors.gtest.xml")
set_tests_properties(test_behaviors PROPERTIES  LABELS "gtest" REQUIRED_FILES "/home/edwinooi/Desktop/foxy_ws/build/nav2_behaviors/test/test_behaviors" TIMEOUT "60" WORKING_DIRECTORY "/home/edwinooi/Desktop/foxy_ws/build/nav2_behaviors/test" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_behaviors/test/CMakeLists.txt;1;ament_add_gtest;/home/edwinooi/Desktop/foxy_ws/src/turtlebot3_simulations/navigation2-humble/nav2_behaviors/test/CMakeLists.txt;0;")
subdirs("../gtest")
