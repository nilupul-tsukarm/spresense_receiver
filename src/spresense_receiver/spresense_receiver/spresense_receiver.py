import requests
import cv2
import numpy as np
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Int32
from cv_bridge import CvBridge

# Update this with your Spresense's IP address
SPRESENSE_IP = "http://192.168.0.235/cam.jpg"

class SpresenseReceiver(Node):
    def __init__(self):
        super().__init__('spresense_receiver')
        self.image_pub = self.create_publisher(Image, 'spresense_image', 10)
        self.tof_pub = self.create_publisher(Int32, 'tof_distance', 10)
        self.bridge = CvBridge()
        self.timer = self.create_timer(0.5, self.fetch_image)  # Fetch every 0.5 sec

    def fetch_image(self):
        try:
            response = requests.get(SPRESENSE_IP, timeout=3)
            if response.status_code == 200:
                tof_distance = int(response.headers.get("X-ToF-Distance", -1))

                # Convert image data
                img_array = np.frombuffer(response.content, np.uint8)
                img = cv2.imdecode(img_array, cv2.IMREAD_COLOR)

                if img is not None:
                    ros_image = self.bridge.cv2_to_imgmsg(img, encoding="bgr8")
                    self.image_pub.publish(ros_image)
                    self.get_logger().info("Published image.")

                # Publish ToF Distance
                msg = Int32()
                msg.data = tof_distance
                self.tof_pub.publish(msg)
                self.get_logger().info(f"Published ToF distance: {tof_distance} mm")

        except Exception as e:
            self.get_logger().error(f"Error fetching data: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = SpresenseReceiver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
