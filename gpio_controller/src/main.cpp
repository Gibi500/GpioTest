#include "rclcpp/rclcpp.hpp"
#include "gpio_controller/gpio_controller_node.hpp"

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GpioControllerNode>());
  rclcpp::shutdown();
  return 0;
}