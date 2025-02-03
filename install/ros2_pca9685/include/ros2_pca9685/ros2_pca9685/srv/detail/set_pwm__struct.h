// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_pca9685:srv/SetPwm.idl
// generated code does not contain a copyright notice

#ifndef ROS2_PCA9685__SRV__DETAIL__SET_PWM__STRUCT_H_
#define ROS2_PCA9685__SRV__DETAIL__SET_PWM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetPwm in the package ros2_pca9685.
typedef struct ros2_pca9685__srv__SetPwm_Request
{
  /// PCA9685 channel number
  uint8_t channel_num;
  /// Taarget position of the servo motor (degrees)
  double target_position;
} ros2_pca9685__srv__SetPwm_Request;

// Struct for a sequence of ros2_pca9685__srv__SetPwm_Request.
typedef struct ros2_pca9685__srv__SetPwm_Request__Sequence
{
  ros2_pca9685__srv__SetPwm_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_pca9685__srv__SetPwm_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'response'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetPwm in the package ros2_pca9685.
typedef struct ros2_pca9685__srv__SetPwm_Response
{
  bool is_success;
  rosidl_runtime_c__String response;
} ros2_pca9685__srv__SetPwm_Response;

// Struct for a sequence of ros2_pca9685__srv__SetPwm_Response.
typedef struct ros2_pca9685__srv__SetPwm_Response__Sequence
{
  ros2_pca9685__srv__SetPwm_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_pca9685__srv__SetPwm_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_PCA9685__SRV__DETAIL__SET_PWM__STRUCT_H_
