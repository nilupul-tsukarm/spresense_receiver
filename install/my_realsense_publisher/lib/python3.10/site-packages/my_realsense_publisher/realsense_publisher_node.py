import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
import pyrealsense2 as rs
import numpy as np
import cv2

class RealSensePublisher(Node):
    def __init__(self):
        super().__init__('realsense_publisher_node')
        self.publisher_rgb = self.create_publisher(Image, 'realsense/color/image_raw', 10)
        self.publisher_depth = self.create_publisher(Image, 'realsense/depth/image_raw', 10)
        self.publisher_info = self.create_publisher(CameraInfo, 'realsense/color/camera_info', 10)
        self.bridge = CvBridge()

        # Configure RealSense pipeline
        self.pipeline = rs.pipeline()
        config = rs.config()
        config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
        config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
        self.pipeline.start(config)

    def publish_images(self):
        frames = self.pipeline.wait_for_frames()

        # Color image
        color_frame = frames.get_color_frame()
        color_image = np.asanyarray(color_frame.get_data())
        color_msg = self.bridge.cv2_to_imgmsg(color_image, 'bgr8')
        self.publisher_rgb.publish(color_msg)

        # Depth image
        depth_frame = frames.get_depth_frame()
        depth_image = np.asanyarray(depth_frame.get_data())
        depth_msg = self.bridge.cv2_to_imgmsg(depth_image, '16UC1')
        self.publisher_depth.publish(depth_msg)

        # Camera info (dummy values for demonstration)
        camera_info_msg = CameraInfo()
        camera_info_msg.header.stamp = self.get_clock().now().to_msg()
        camera_info_msg.width = 640
        camera_info_msg.height = 480
        self.publisher_info.publish(camera_info_msg)

    def spin(self):
        while rclpy.ok():
            self.publish_images()

def main(args=None):
    rclpy.init(args=args)
    node = RealSensePublisher()
    try:
        node.spin()
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
