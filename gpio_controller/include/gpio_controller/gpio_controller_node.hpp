#pragma once

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include <pigpio.h>

class GpioControllerNode : public rclcpp::Node 
{
public:
    GpioControllerNode() : Node("gpio_controller") {
        RCLCPP_INFO(this->get_logger(), "Starting GPIO controller Node ...");

        joySubscriber = this->create_subscription<sensor_msgs::msg::Joy>(
        "/joy",          // topic
        10,              // The depth of the subscription's incoming message queue.
        std::bind(&GpioControllerNode::joy_callback, this, std::placeholders::_1) // callback takes 1 arg
        );  
    }

private:
    void joy_callback(sensor_msgs::msg::Joy::UniquePtr msg){
        // TODO: Need to drop some messages. Joy is publishing to fast. Tried topic_tools drop but can't build it.
        // Crude solution for getting this to work
        if ((++counter) % 4 != 0) return;

        RCLCPP_INFO(this->get_logger(), "Processing Joystick Message");
        int buttonX = msg->buttons[3];                      // lichten
        if(buttonX > 0.5){
            gpioPWM(13, 128);
        }else{
            gpioPWM(13, 0);
        }
    }
 
private:
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joySubscriber;
    int counter = 0;
};