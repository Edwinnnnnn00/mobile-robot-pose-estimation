// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_aruco_interfaces:msg/ArucoMarkersWithRotMatrix.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__BUILDER_HPP_
#define ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_aruco_interfaces/msg/detail/aruco_markers_with_rot_matrix__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_aruco_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArucoMarkersWithRotMatrix_rot_mat
{
public:
  explicit Init_ArucoMarkersWithRotMatrix_rot_mat(::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix & msg)
  : msg_(msg)
  {}
  ::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix rot_mat(::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix::_rot_mat_type arg)
  {
    msg_.rot_mat = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix msg_;
};

class Init_ArucoMarkersWithRotMatrix_poses
{
public:
  explicit Init_ArucoMarkersWithRotMatrix_poses(::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix & msg)
  : msg_(msg)
  {}
  Init_ArucoMarkersWithRotMatrix_rot_mat poses(::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix::_poses_type arg)
  {
    msg_.poses = std::move(arg);
    return Init_ArucoMarkersWithRotMatrix_rot_mat(msg_);
  }

private:
  ::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix msg_;
};

class Init_ArucoMarkersWithRotMatrix_marker_ids
{
public:
  explicit Init_ArucoMarkersWithRotMatrix_marker_ids(::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix & msg)
  : msg_(msg)
  {}
  Init_ArucoMarkersWithRotMatrix_poses marker_ids(::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix::_marker_ids_type arg)
  {
    msg_.marker_ids = std::move(arg);
    return Init_ArucoMarkersWithRotMatrix_poses(msg_);
  }

private:
  ::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix msg_;
};

class Init_ArucoMarkersWithRotMatrix_header
{
public:
  Init_ArucoMarkersWithRotMatrix_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArucoMarkersWithRotMatrix_marker_ids header(::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ArucoMarkersWithRotMatrix_marker_ids(msg_);
  }

private:
  ::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_aruco_interfaces::msg::ArucoMarkersWithRotMatrix>()
{
  return ros2_aruco_interfaces::msg::builder::Init_ArucoMarkersWithRotMatrix_header();
}

}  // namespace ros2_aruco_interfaces

#endif  // ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__BUILDER_HPP_
