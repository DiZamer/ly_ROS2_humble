// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_service_interfaces:srv/SetVelocity.idl
// generated code does not contain a copyright notice

#ifndef MY_SERVICE_INTERFACES__SRV__DETAIL__SET_VELOCITY__BUILDER_HPP_
#define MY_SERVICE_INTERFACES__SRV__DETAIL__SET_VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_service_interfaces/srv/detail/set_velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_service_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetVelocity_Request_angular
{
public:
  explicit Init_SetVelocity_Request_angular(::my_service_interfaces::srv::SetVelocity_Request & msg)
  : msg_(msg)
  {}
  ::my_service_interfaces::srv::SetVelocity_Request angular(::my_service_interfaces::srv::SetVelocity_Request::_angular_type arg)
  {
    msg_.angular = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_service_interfaces::srv::SetVelocity_Request msg_;
};

class Init_SetVelocity_Request_linear
{
public:
  Init_SetVelocity_Request_linear()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetVelocity_Request_angular linear(::my_service_interfaces::srv::SetVelocity_Request::_linear_type arg)
  {
    msg_.linear = std::move(arg);
    return Init_SetVelocity_Request_angular(msg_);
  }

private:
  ::my_service_interfaces::srv::SetVelocity_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_service_interfaces::srv::SetVelocity_Request>()
{
  return my_service_interfaces::srv::builder::Init_SetVelocity_Request_linear();
}

}  // namespace my_service_interfaces


namespace my_service_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetVelocity_Response_message
{
public:
  explicit Init_SetVelocity_Response_message(::my_service_interfaces::srv::SetVelocity_Response & msg)
  : msg_(msg)
  {}
  ::my_service_interfaces::srv::SetVelocity_Response message(::my_service_interfaces::srv::SetVelocity_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_service_interfaces::srv::SetVelocity_Response msg_;
};

class Init_SetVelocity_Response_success
{
public:
  Init_SetVelocity_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetVelocity_Response_message success(::my_service_interfaces::srv::SetVelocity_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetVelocity_Response_message(msg_);
  }

private:
  ::my_service_interfaces::srv::SetVelocity_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_service_interfaces::srv::SetVelocity_Response>()
{
  return my_service_interfaces::srv::builder::Init_SetVelocity_Response_success();
}

}  // namespace my_service_interfaces

#endif  // MY_SERVICE_INTERFACES__SRV__DETAIL__SET_VELOCITY__BUILDER_HPP_
