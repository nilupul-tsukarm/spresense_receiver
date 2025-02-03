// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_pca9685:srv/SetPwm.idl
// generated code does not contain a copyright notice

#ifndef ROS2_PCA9685__SRV__DETAIL__SET_PWM__STRUCT_HPP_
#define ROS2_PCA9685__SRV__DETAIL__SET_PWM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_pca9685__srv__SetPwm_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_pca9685__srv__SetPwm_Request __declspec(deprecated)
#endif

namespace ros2_pca9685
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetPwm_Request_
{
  using Type = SetPwm_Request_<ContainerAllocator>;

  explicit SetPwm_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->channel_num = 0;
      this->target_position = 0.0;
    }
  }

  explicit SetPwm_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->channel_num = 0;
      this->target_position = 0.0;
    }
  }

  // field types and members
  using _channel_num_type =
    uint8_t;
  _channel_num_type channel_num;
  using _target_position_type =
    double;
  _target_position_type target_position;

  // setters for named parameter idiom
  Type & set__channel_num(
    const uint8_t & _arg)
  {
    this->channel_num = _arg;
    return *this;
  }
  Type & set__target_position(
    const double & _arg)
  {
    this->target_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_pca9685__srv__SetPwm_Request
    std::shared_ptr<ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_pca9685__srv__SetPwm_Request
    std::shared_ptr<ros2_pca9685::srv::SetPwm_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPwm_Request_ & other) const
  {
    if (this->channel_num != other.channel_num) {
      return false;
    }
    if (this->target_position != other.target_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPwm_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPwm_Request_

// alias to use template instance with default allocator
using SetPwm_Request =
  ros2_pca9685::srv::SetPwm_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_pca9685


#ifndef _WIN32
# define DEPRECATED__ros2_pca9685__srv__SetPwm_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_pca9685__srv__SetPwm_Response __declspec(deprecated)
#endif

namespace ros2_pca9685
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetPwm_Response_
{
  using Type = SetPwm_Response_<ContainerAllocator>;

  explicit SetPwm_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_success = false;
      this->response = "";
    }
  }

  explicit SetPwm_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : response(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_success = false;
      this->response = "";
    }
  }

  // field types and members
  using _is_success_type =
    bool;
  _is_success_type is_success;
  using _response_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__is_success(
    const bool & _arg)
  {
    this->is_success = _arg;
    return *this;
  }
  Type & set__response(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_pca9685__srv__SetPwm_Response
    std::shared_ptr<ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_pca9685__srv__SetPwm_Response
    std::shared_ptr<ros2_pca9685::srv::SetPwm_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPwm_Response_ & other) const
  {
    if (this->is_success != other.is_success) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPwm_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPwm_Response_

// alias to use template instance with default allocator
using SetPwm_Response =
  ros2_pca9685::srv::SetPwm_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_pca9685

namespace ros2_pca9685
{

namespace srv
{

struct SetPwm
{
  using Request = ros2_pca9685::srv::SetPwm_Request;
  using Response = ros2_pca9685::srv::SetPwm_Response;
};

}  // namespace srv

}  // namespace ros2_pca9685

#endif  // ROS2_PCA9685__SRV__DETAIL__SET_PWM__STRUCT_HPP_
