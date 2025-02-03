# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_pca9685:srv/SetPwm.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetPwm_Request(type):
    """Metaclass of message 'SetPwm_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_pca9685')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_pca9685.srv.SetPwm_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_pwm__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_pwm__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_pwm__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_pwm__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_pwm__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetPwm_Request(metaclass=Metaclass_SetPwm_Request):
    """Message class 'SetPwm_Request'."""

    __slots__ = [
        '_channel_num',
        '_target_position',
    ]

    _fields_and_field_types = {
        'channel_num': 'uint8',
        'target_position': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.channel_num = kwargs.get('channel_num', int())
        self.target_position = kwargs.get('target_position', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.channel_num != other.channel_num:
            return False
        if self.target_position != other.target_position:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def channel_num(self):
        """Message field 'channel_num'."""
        return self._channel_num

    @channel_num.setter
    def channel_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'channel_num' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'channel_num' field must be an unsigned integer in [0, 255]"
        self._channel_num = value

    @builtins.property
    def target_position(self):
        """Message field 'target_position'."""
        return self._target_position

    @target_position.setter
    def target_position(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_position' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'target_position' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._target_position = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetPwm_Response(type):
    """Metaclass of message 'SetPwm_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_pca9685')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_pca9685.srv.SetPwm_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_pwm__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_pwm__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_pwm__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_pwm__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_pwm__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetPwm_Response(metaclass=Metaclass_SetPwm_Response):
    """Message class 'SetPwm_Response'."""

    __slots__ = [
        '_is_success',
        '_response',
    ]

    _fields_and_field_types = {
        'is_success': 'boolean',
        'response': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_success = kwargs.get('is_success', bool())
        self.response = kwargs.get('response', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.is_success != other.is_success:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_success(self):
        """Message field 'is_success'."""
        return self._is_success

    @is_success.setter
    def is_success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_success' field must be of type 'bool'"
        self._is_success = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'response' field must be of type 'str'"
        self._response = value


class Metaclass_SetPwm(type):
    """Metaclass of service 'SetPwm'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_pca9685')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_pca9685.srv.SetPwm')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_pwm

            from ros2_pca9685.srv import _set_pwm
            if _set_pwm.Metaclass_SetPwm_Request._TYPE_SUPPORT is None:
                _set_pwm.Metaclass_SetPwm_Request.__import_type_support__()
            if _set_pwm.Metaclass_SetPwm_Response._TYPE_SUPPORT is None:
                _set_pwm.Metaclass_SetPwm_Response.__import_type_support__()


class SetPwm(metaclass=Metaclass_SetPwm):
    from ros2_pca9685.srv._set_pwm import SetPwm_Request as Request
    from ros2_pca9685.srv._set_pwm import SetPwm_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
