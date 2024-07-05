// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_aruco_interfaces:msg/ArucoMarkersWithRotMatrix.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__STRUCT_H_
#define ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'marker_ids'
// Member 'rot_mat'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'poses'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/ArucoMarkersWithRotMatrix in the package ros2_aruco_interfaces.
typedef struct ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__int64__Sequence marker_ids;
  geometry_msgs__msg__Pose__Sequence poses;
  /// Matrix3x3
  rosidl_runtime_c__double__Sequence rot_mat;
} ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix;

// Struct for a sequence of ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix.
typedef struct ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence
{
  ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__STRUCT_H_
