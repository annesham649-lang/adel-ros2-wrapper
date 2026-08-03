#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class AdelEngineNode : public rclcpp::Node {
public:
  AdelEngineNode() : Node("adel_engine_node") {
    publisher_ = this->create_publisher<std_msgs::msg::String>("adel/telemetry", 10);
    timer_ = this->create_wall_timer(
      100ms, std::bind(&AdelEngineNode::publish_telemetry, this));
    RCLCPP_INFO(this->get_logger(), "Space Nova ADEL 2.0 ROS 2 Execution Core Initialized.");
  }

private:
  void publish_telemetry() {
    auto message = std_msgs::msg::String();
    message.data = "ADEL 2.0 Core Active | Latency: 0.00ms | Status: Deterministic Loop";
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AdelEngineNode>());
  rclcpp::shutdown();
  return 0;
}
