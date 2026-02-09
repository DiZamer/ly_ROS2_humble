import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/ly_ROS2_humble/ros2_ws/install/my_service_client'
