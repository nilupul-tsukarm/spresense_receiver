// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_pca9685:srv/SetPwm.idl
// generated code does not contain a copyright notice

#ifndef ROS2_PCA9685__SRV__DETAIL__SET_PWM__TRAITS_HPP_
#define ROS2_PCA9685__SRV__DETAIL__SET_PWM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_pca9685/srv/detail/set_pwm__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_pca9685
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPwm_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: channel_num
  {
    out << "channel_num: ";
    rosidl_generator_traits::value_to_yaml(msg.channel_num, out);
    out << ", ";
  }

  // member: target_position
  {
    out << "target_position: ";
    rosidl_generator_traits::value_to_yaml(msg.target_position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPwm_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: channel_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "channel_num: ";
    rosidl_generator_traits::value_to_yaml(msg.channel_num, out);
    out << "\n";
  }

  // member: target_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_position: ";
    rosidl_generator_traits::value_to_yaml(msg.target_position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPwm_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_pca9685

namespace rosidl_generator_traits
{

[[deprecated("use ros2_pca9685::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_pca9685::srv::SetPwm_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_pca9685::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_pca9685::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_pca9685::srv::SetPwm_Request & msg)
{
  return ros2_pca9685::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_pca9685::srv::SetPwm_Request>()
{
  return "ros2_pca9685::srv::SetPwm_Request";
}

template<>
inline const char * name<ros2_pca9685::srv::SetPwm_Request>()
{
  return "ros2_pca9685/srv/SetPwm_Request";
}

template<>
struct has_fixed_size<ros2_pca9685::srv::SetPwm_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_pca9685::srv::SetPwm_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_pca9685::srv::SetPwm_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros2_pca9685
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPwm_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_success
  {
    out << "is_success: ";
    rosidl_generator_traits::value_to_yaml(msg.is_success, out);
    out << ", ";
  }

  // member: response
  {
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPwm_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_success: ";
    rosidl_generator_traits::value_to_yaml(msg.is_success, out);
    out << "\n";
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response: ";
    rosidl_generator_traits::value_to_yaml(msg.response, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPwm_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_pca9685

namespace rosidl_generator_traits
{

[[deprecated("use ros2_pca9685::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_pca9685::srv::SetPwm_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_pca9685::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_pca9685::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_pca9685::srv::SetPwm_Response & msg)
{
  return ros2_pca9685::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_pca9685::srv::SetPwm_Response>()
{
  return "ros2_pca9685::srv::SetPwm_Response";
}

template<>
inline const char * name<ros2_pca9685::srv::SetPwm_Response>()
{
  return "ros2_pca9685/srv/SetPwm_Response";
}

template<>
struct has_fixed_size<ros2_pca9685::srv::SetPwm_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_pca9685::srv::SetPwm_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_pca9685::srv::SetPwm_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_pca9685::srv::SetPwm>()
{
  return "ros2_pca9685::srv::SetPwm";
}

template<>
inline const char * name<ros2_pca9685::srv::SetPwm>()
{
  return "ros2_pca9685/srv/SetPwm";
}

template<>
struct has_fixed_size<ros2_pca9685::srv::SetPwm>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_pca9685::srv::SetPwm_Request>::value &&
    has_fixed_size<ros2_pca9685::srv::SetPwm_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_pca9685::srv::SetPwm>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_pca9685::srv::SetPwm_Request>::value &&
    has_bounded_size<ros2_pca9685::srv::SetPwm_Response>::value
  >
{
};

template<>
struct is_service<ros2_pca9685::srv::SetPwm>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_pca9685::srv::SetPwm_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_pca9685::srv::SetPwm_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_PCA9685__SRV__DETAIL__SET_PWM__TRAITS_HPP_
