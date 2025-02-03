// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_pca9685:srv/SetPwm.idl
// generated code does not contain a copyright notice
#include "ros2_pca9685/srv/detail/set_pwm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
ros2_pca9685__srv__SetPwm_Request__init(ros2_pca9685__srv__SetPwm_Request * msg)
{
  if (!msg) {
    return false;
  }
  // channel_num
  // target_position
  return true;
}

void
ros2_pca9685__srv__SetPwm_Request__fini(ros2_pca9685__srv__SetPwm_Request * msg)
{
  if (!msg) {
    return;
  }
  // channel_num
  // target_position
}

bool
ros2_pca9685__srv__SetPwm_Request__are_equal(const ros2_pca9685__srv__SetPwm_Request * lhs, const ros2_pca9685__srv__SetPwm_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // channel_num
  if (lhs->channel_num != rhs->channel_num) {
    return false;
  }
  // target_position
  if (lhs->target_position != rhs->target_position) {
    return false;
  }
  return true;
}

bool
ros2_pca9685__srv__SetPwm_Request__copy(
  const ros2_pca9685__srv__SetPwm_Request * input,
  ros2_pca9685__srv__SetPwm_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // channel_num
  output->channel_num = input->channel_num;
  // target_position
  output->target_position = input->target_position;
  return true;
}

ros2_pca9685__srv__SetPwm_Request *
ros2_pca9685__srv__SetPwm_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_pca9685__srv__SetPwm_Request * msg = (ros2_pca9685__srv__SetPwm_Request *)allocator.allocate(sizeof(ros2_pca9685__srv__SetPwm_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_pca9685__srv__SetPwm_Request));
  bool success = ros2_pca9685__srv__SetPwm_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_pca9685__srv__SetPwm_Request__destroy(ros2_pca9685__srv__SetPwm_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_pca9685__srv__SetPwm_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_pca9685__srv__SetPwm_Request__Sequence__init(ros2_pca9685__srv__SetPwm_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_pca9685__srv__SetPwm_Request * data = NULL;

  if (size) {
    data = (ros2_pca9685__srv__SetPwm_Request *)allocator.zero_allocate(size, sizeof(ros2_pca9685__srv__SetPwm_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_pca9685__srv__SetPwm_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_pca9685__srv__SetPwm_Request__fini(&data[i - 1]);
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
ros2_pca9685__srv__SetPwm_Request__Sequence__fini(ros2_pca9685__srv__SetPwm_Request__Sequence * array)
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
      ros2_pca9685__srv__SetPwm_Request__fini(&array->data[i]);
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

ros2_pca9685__srv__SetPwm_Request__Sequence *
ros2_pca9685__srv__SetPwm_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_pca9685__srv__SetPwm_Request__Sequence * array = (ros2_pca9685__srv__SetPwm_Request__Sequence *)allocator.allocate(sizeof(ros2_pca9685__srv__SetPwm_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_pca9685__srv__SetPwm_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_pca9685__srv__SetPwm_Request__Sequence__destroy(ros2_pca9685__srv__SetPwm_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_pca9685__srv__SetPwm_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_pca9685__srv__SetPwm_Request__Sequence__are_equal(const ros2_pca9685__srv__SetPwm_Request__Sequence * lhs, const ros2_pca9685__srv__SetPwm_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_pca9685__srv__SetPwm_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_pca9685__srv__SetPwm_Request__Sequence__copy(
  const ros2_pca9685__srv__SetPwm_Request__Sequence * input,
  ros2_pca9685__srv__SetPwm_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_pca9685__srv__SetPwm_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_pca9685__srv__SetPwm_Request * data =
      (ros2_pca9685__srv__SetPwm_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_pca9685__srv__SetPwm_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_pca9685__srv__SetPwm_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_pca9685__srv__SetPwm_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `response`
#include "rosidl_runtime_c/string_functions.h"

bool
ros2_pca9685__srv__SetPwm_Response__init(ros2_pca9685__srv__SetPwm_Response * msg)
{
  if (!msg) {
    return false;
  }
  // is_success
  // response
  if (!rosidl_runtime_c__String__init(&msg->response)) {
    ros2_pca9685__srv__SetPwm_Response__fini(msg);
    return false;
  }
  return true;
}

void
ros2_pca9685__srv__SetPwm_Response__fini(ros2_pca9685__srv__SetPwm_Response * msg)
{
  if (!msg) {
    return;
  }
  // is_success
  // response
  rosidl_runtime_c__String__fini(&msg->response);
}

bool
ros2_pca9685__srv__SetPwm_Response__are_equal(const ros2_pca9685__srv__SetPwm_Response * lhs, const ros2_pca9685__srv__SetPwm_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_success
  if (lhs->is_success != rhs->is_success) {
    return false;
  }
  // response
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
ros2_pca9685__srv__SetPwm_Response__copy(
  const ros2_pca9685__srv__SetPwm_Response * input,
  ros2_pca9685__srv__SetPwm_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // is_success
  output->is_success = input->is_success;
  // response
  if (!rosidl_runtime_c__String__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

ros2_pca9685__srv__SetPwm_Response *
ros2_pca9685__srv__SetPwm_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_pca9685__srv__SetPwm_Response * msg = (ros2_pca9685__srv__SetPwm_Response *)allocator.allocate(sizeof(ros2_pca9685__srv__SetPwm_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_pca9685__srv__SetPwm_Response));
  bool success = ros2_pca9685__srv__SetPwm_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_pca9685__srv__SetPwm_Response__destroy(ros2_pca9685__srv__SetPwm_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_pca9685__srv__SetPwm_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_pca9685__srv__SetPwm_Response__Sequence__init(ros2_pca9685__srv__SetPwm_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_pca9685__srv__SetPwm_Response * data = NULL;

  if (size) {
    data = (ros2_pca9685__srv__SetPwm_Response *)allocator.zero_allocate(size, sizeof(ros2_pca9685__srv__SetPwm_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_pca9685__srv__SetPwm_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_pca9685__srv__SetPwm_Response__fini(&data[i - 1]);
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
ros2_pca9685__srv__SetPwm_Response__Sequence__fini(ros2_pca9685__srv__SetPwm_Response__Sequence * array)
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
      ros2_pca9685__srv__SetPwm_Response__fini(&array->data[i]);
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

ros2_pca9685__srv__SetPwm_Response__Sequence *
ros2_pca9685__srv__SetPwm_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_pca9685__srv__SetPwm_Response__Sequence * array = (ros2_pca9685__srv__SetPwm_Response__Sequence *)allocator.allocate(sizeof(ros2_pca9685__srv__SetPwm_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_pca9685__srv__SetPwm_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_pca9685__srv__SetPwm_Response__Sequence__destroy(ros2_pca9685__srv__SetPwm_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_pca9685__srv__SetPwm_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_pca9685__srv__SetPwm_Response__Sequence__are_equal(const ros2_pca9685__srv__SetPwm_Response__Sequence * lhs, const ros2_pca9685__srv__SetPwm_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_pca9685__srv__SetPwm_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_pca9685__srv__SetPwm_Response__Sequence__copy(
  const ros2_pca9685__srv__SetPwm_Response__Sequence * input,
  ros2_pca9685__srv__SetPwm_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_pca9685__srv__SetPwm_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_pca9685__srv__SetPwm_Response * data =
      (ros2_pca9685__srv__SetPwm_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_pca9685__srv__SetPwm_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_pca9685__srv__SetPwm_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_pca9685__srv__SetPwm_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
