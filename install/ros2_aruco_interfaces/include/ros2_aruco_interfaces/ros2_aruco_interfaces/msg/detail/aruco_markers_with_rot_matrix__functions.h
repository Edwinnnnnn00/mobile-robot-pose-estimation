// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ros2_aruco_interfaces:msg/ArucoMarkersWithRotMatrix.idl
// generated code does not contain a copyright notice

#ifndef ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__FUNCTIONS_H_
#define ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ros2_aruco_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "ros2_aruco_interfaces/msg/detail/aruco_markers_with_rot_matrix__struct.h"

/// Initialize msg/ArucoMarkersWithRotMatrix message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix
 * )) before or use
 * ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__init(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * msg);

/// Finalize msg/ArucoMarkersWithRotMatrix message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
void
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * msg);

/// Create msg/ArucoMarkersWithRotMatrix message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix *
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__create();

/// Destroy msg/ArucoMarkersWithRotMatrix message.
/**
 * It calls
 * ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
void
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__destroy(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * msg);

/// Check for msg/ArucoMarkersWithRotMatrix message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__are_equal(const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * lhs, const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * rhs);

/// Copy a msg/ArucoMarkersWithRotMatrix message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__copy(
  const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * input,
  ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * output);

/// Initialize array of msg/ArucoMarkersWithRotMatrix messages.
/**
 * It allocates the memory for the number of elements and calls
 * ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__init(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * array, size_t size);

/// Finalize array of msg/ArucoMarkersWithRotMatrix messages.
/**
 * It calls
 * ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
void
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__fini(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * array);

/// Create array of msg/ArucoMarkersWithRotMatrix messages.
/**
 * It allocates the memory for the array and calls
 * ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence *
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__create(size_t size);

/// Destroy array of msg/ArucoMarkersWithRotMatrix messages.
/**
 * It calls
 * ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
void
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__destroy(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * array);

/// Check for msg/ArucoMarkersWithRotMatrix message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__are_equal(const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * lhs, const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * rhs);

/// Copy an array of msg/ArucoMarkersWithRotMatrix messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ros2_aruco_interfaces
bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__copy(
  const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * input,
  ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROS2_ARUCO_INTERFACES__MSG__DETAIL__ARUCO_MARKERS_WITH_ROT_MATRIX__FUNCTIONS_H_
