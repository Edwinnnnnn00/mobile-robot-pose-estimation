set(_AMENT_PACKAGE_NAME "nav2_controller")
set(nav2_controller_VERSION "1.1.15")
set(nav2_controller_MAINTAINER "Carl Delsey <carl.r.delsey@intel.com>")
set(nav2_controller_BUILD_DEPENDS "nav2_common" "angles" "rclcpp" "rclcpp_action" "std_msgs" "nav2_util" "nav2_msgs" "nav_2d_utils" "nav_2d_msgs" "nav2_core" "pluginlib")
set(nav2_controller_BUILDTOOL_DEPENDS "ament_cmake")
set(nav2_controller_BUILD_EXPORT_DEPENDS "angles" "rclcpp" "rclcpp_action" "std_msgs" "nav2_util" "nav2_msgs" "nav_2d_utils" "nav_2d_msgs" "nav2_core" "pluginlib")
set(nav2_controller_BUILDTOOL_EXPORT_DEPENDS )
set(nav2_controller_EXEC_DEPENDS "angles" "rclcpp" "rclcpp_action" "std_msgs" "nav2_util" "nav2_msgs" "nav_2d_utils" "nav_2d_msgs" "nav2_core" "pluginlib")
set(nav2_controller_TEST_DEPENDS "ament_lint_common" "ament_lint_auto" "ament_cmake_gtest" "ament_cmake_pytest")
set(nav2_controller_GROUP_DEPENDS )
set(nav2_controller_MEMBER_OF_GROUPS )
set(nav2_controller_DEPRECATED "")
set(nav2_controller_EXPORT_TAGS)
list(APPEND nav2_controller_EXPORT_TAGS "<build_type>ament_cmake</build_type>")
list(APPEND nav2_controller_EXPORT_TAGS "<nav2_core plugin=\"plugins.xml\"/>")
