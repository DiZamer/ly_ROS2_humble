// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_service_interfaces:srv/SetVelocity.idl
// generated code does not contain a copyright notice

#ifndef MY_SERVICE_INTERFACES__SRV__DETAIL__SET_VELOCITY__TRAITS_HPP_
#define MY_SERVICE_INTERFACES__SRV__DETAIL__SET_VELOCITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_service_interfaces/srv/detail/set_velocity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_service_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetVelocity_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: linear
  {
    out << "linear: ";
    rosidl_generator_traits::value_to_yaml(msg.linear, out);
    out << ", ";
  }

  // member: angular
  {
    out << "angular: ";
    rosidl_generator_traits::value_to_yaml(msg.angular, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetVelocity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear: ";
    rosidl_generator_traits::value_to_yaml(msg.linear, out);
    out << "\n";
  }

  // member: angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular: ";
    rosidl_generator_traits::value_to_yaml(msg.angular, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetVelocity_Request & msg, bool use_flow_style = false)
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

}  // namespace my_service_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_service_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_service_interfaces::srv::SetVelocity_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_service_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_service_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_service_interfaces::srv::SetVelocity_Request & msg)
{
  return my_service_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_service_interfaces::srv::SetVelocity_Request>()
{
  return "my_service_interfaces::srv::SetVelocity_Request";
}

template<>
inline const char * name<my_service_interfaces::srv::SetVelocity_Request>()
{
  return "my_service_interfaces/srv/SetVelocity_Request";
}

template<>
struct has_fixed_size<my_service_interfaces::srv::SetVelocity_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_service_interfaces::srv::SetVelocity_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_service_interfaces::srv::SetVelocity_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_service_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetVelocity_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetVelocity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetVelocity_Response & msg, bool use_flow_style = false)
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

}  // namespace my_service_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use my_service_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_service_interfaces::srv::SetVelocity_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_service_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_service_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_service_interfaces::srv::SetVelocity_Response & msg)
{
  return my_service_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_service_interfaces::srv::SetVelocity_Response>()
{
  return "my_service_interfaces::srv::SetVelocity_Response";
}

template<>
inline const char * name<my_service_interfaces::srv::SetVelocity_Response>()
{
  return "my_service_interfaces/srv/SetVelocity_Response";
}

template<>
struct has_fixed_size<my_service_interfaces::srv::SetVelocity_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_service_interfaces::srv::SetVelocity_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_service_interfaces::srv::SetVelocity_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_service_interfaces::srv::SetVelocity>()
{
  return "my_service_interfaces::srv::SetVelocity";
}

template<>
inline const char * name<my_service_interfaces::srv::SetVelocity>()
{
  return "my_service_interfaces/srv/SetVelocity";
}

template<>
struct has_fixed_size<my_service_interfaces::srv::SetVelocity>
  : std::integral_constant<
    bool,
    has_fixed_size<my_service_interfaces::srv::SetVelocity_Request>::value &&
    has_fixed_size<my_service_interfaces::srv::SetVelocity_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_service_interfaces::srv::SetVelocity>
  : std::integral_constant<
    bool,
    has_bounded_size<my_service_interfaces::srv::SetVelocity_Request>::value &&
    has_bounded_size<my_service_interfaces::srv::SetVelocity_Response>::value
  >
{
};

template<>
struct is_service<my_service_interfaces::srv::SetVelocity>
  : std::true_type
{
};

template<>
struct is_service_request<my_service_interfaces::srv::SetVelocity_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_service_interfaces::srv::SetVelocity_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_SERVICE_INTERFACES__SRV__DETAIL__SET_VELOCITY__TRAITS_HPP_
