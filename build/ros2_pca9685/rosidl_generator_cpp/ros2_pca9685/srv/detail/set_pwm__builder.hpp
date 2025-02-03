// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_pca9685:srv/SetPwm.idl
// generated code does not contain a copyright notice

#ifndef ROS2_PCA9685__SRV__DETAIL__SET_PWM__BUILDER_HPP_
#define ROS2_PCA9685__SRV__DETAIL__SET_PWM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_pca9685/srv/detail/set_pwm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_pca9685
{

namespace srv
{

namespace builder
{

class Init_SetPwm_Request_target_position
{
public:
  explicit Init_SetPwm_Request_target_position(::ros2_pca9685::srv::SetPwm_Request & msg)
  : msg_(msg)
  {}
  ::ros2_pca9685::srv::SetPwm_Request target_position(::ros2_pca9685::srv::SetPwm_Request::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_pca9685::srv::SetPwm_Request msg_;
};

class Init_SetPwm_Request_channel_num
{
public:
  Init_SetPwm_Request_channel_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPwm_Request_target_position channel_num(::ros2_pca9685::srv::SetPwm_Request::_channel_num_type arg)
  {
    msg_.channel_num = std::move(arg);
    return Init_SetPwm_Request_target_position(msg_);
  }

private:
  ::ros2_pca9685::srv::SetPwm_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_pca9685::srv::SetPwm_Request>()
{
  return ros2_pca9685::srv::builder::Init_SetPwm_Request_channel_num();
}

}  // namespace ros2_pca9685


namespace ros2_pca9685
{

namespace srv
{

namespace builder
{

class Init_SetPwm_Response_response
{
public:
  explicit Init_SetPwm_Response_response(::ros2_pca9685::srv::SetPwm_Response & msg)
  : msg_(msg)
  {}
  ::ros2_pca9685::srv::SetPwm_Response response(::ros2_pca9685::srv::SetPwm_Response::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_pca9685::srv::SetPwm_Response msg_;
};

class Init_SetPwm_Response_is_success
{
public:
  Init_SetPwm_Response_is_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPwm_Response_response is_success(::ros2_pca9685::srv::SetPwm_Response::_is_success_type arg)
  {
    msg_.is_success = std::move(arg);
    return Init_SetPwm_Response_response(msg_);
  }

private:
  ::ros2_pca9685::srv::SetPwm_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_pca9685::srv::SetPwm_Response>()
{
  return ros2_pca9685::srv::builder::Init_SetPwm_Response_is_success();
}

}  // namespace ros2_pca9685

#endif  // ROS2_PCA9685__SRV__DETAIL__SET_PWM__BUILDER_HPP_
