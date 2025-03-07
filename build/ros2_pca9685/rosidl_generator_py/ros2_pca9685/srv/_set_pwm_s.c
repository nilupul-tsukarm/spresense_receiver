// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ros2_pca9685:srv/SetPwm.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ros2_pca9685/srv/detail/set_pwm__struct.h"
#include "ros2_pca9685/srv/detail/set_pwm__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ros2_pca9685__srv__set_pwm__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ros2_pca9685.srv._set_pwm.SetPwm_Request", full_classname_dest, 40) == 0);
  }
  ros2_pca9685__srv__SetPwm_Request * ros_message = _ros_message;
  {  // channel_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "channel_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->channel_num = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // target_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_position");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_position = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ros2_pca9685__srv__set_pwm__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetPwm_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ros2_pca9685.srv._set_pwm");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetPwm_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ros2_pca9685__srv__SetPwm_Request * ros_message = (ros2_pca9685__srv__SetPwm_Request *)raw_ros_message;
  {  // channel_num
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->channel_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "channel_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_position
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "ros2_pca9685/srv/detail/set_pwm__struct.h"
// already included above
// #include "ros2_pca9685/srv/detail/set_pwm__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ros2_pca9685__srv__set_pwm__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ros2_pca9685.srv._set_pwm.SetPwm_Response", full_classname_dest, 41) == 0);
  }
  ros2_pca9685__srv__SetPwm_Response * ros_message = _ros_message;
  {  // is_success
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // response
    PyObject * field = PyObject_GetAttrString(_pymsg, "response");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->response, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ros2_pca9685__srv__set_pwm__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SetPwm_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ros2_pca9685.srv._set_pwm");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SetPwm_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ros2_pca9685__srv__SetPwm_Response * ros_message = (ros2_pca9685__srv__SetPwm_Response *)raw_ros_message;
  {  // is_success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // response
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->response.data,
      strlen(ros_message->response.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "response", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
