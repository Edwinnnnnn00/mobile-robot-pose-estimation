// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_aruco_interfaces:msg/ArucoMarkersWithRotMatrix.idl
// generated code does not contain a copyright notice
#include "ros2_aruco_interfaces/msg/detail/aruco_markers_with_rot_matrix__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `marker_ids`
// Member `rot_mat`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `poses`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__init(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(msg);
    return false;
  }
  // marker_ids
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->marker_ids, 0)) {
    ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(msg);
    return false;
  }
  // poses
  if (!geometry_msgs__msg__Pose__Sequence__init(&msg->poses, 0)) {
    ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(msg);
    return false;
  }
  // rot_mat
  if (!rosidl_runtime_c__double__Sequence__init(&msg->rot_mat, 0)) {
    ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(msg);
    return false;
  }
  return true;
}

void
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // marker_ids
  rosidl_runtime_c__int64__Sequence__fini(&msg->marker_ids);
  // poses
  geometry_msgs__msg__Pose__Sequence__fini(&msg->poses);
  // rot_mat
  rosidl_runtime_c__double__Sequence__fini(&msg->rot_mat);
}

bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__are_equal(const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * lhs, const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // marker_ids
  if (!rosidl_runtime_c__int64__Sequence__are_equal(
      &(lhs->marker_ids), &(rhs->marker_ids)))
  {
    return false;
  }
  // poses
  if (!geometry_msgs__msg__Pose__Sequence__are_equal(
      &(lhs->poses), &(rhs->poses)))
  {
    return false;
  }
  // rot_mat
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->rot_mat), &(rhs->rot_mat)))
  {
    return false;
  }
  return true;
}

bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__copy(
  const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * input,
  ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // marker_ids
  if (!rosidl_runtime_c__int64__Sequence__copy(
      &(input->marker_ids), &(output->marker_ids)))
  {
    return false;
  }
  // poses
  if (!geometry_msgs__msg__Pose__Sequence__copy(
      &(input->poses), &(output->poses)))
  {
    return false;
  }
  // rot_mat
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->rot_mat), &(output->rot_mat)))
  {
    return false;
  }
  return true;
}

ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix *
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * msg = (ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix *)allocator.allocate(sizeof(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix));
  bool success = ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__destroy(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__init(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * data = NULL;

  if (size) {
    data = (ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix *)allocator.zero_allocate(size, sizeof(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__fini(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence *
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * array = (ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence *)allocator.allocate(sizeof(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__destroy(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__are_equal(const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * lhs, const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence__copy(
  const ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * input,
  ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix * data =
      (ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_aruco_interfaces__msg__ArucoMarkersWithRotMatrix__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
