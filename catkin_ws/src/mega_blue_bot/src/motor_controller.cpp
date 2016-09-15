//For use together with teleop_twist_keyboard.py

#include <ros/ros.h>
#include <std_msgs/Int16.h>
#include <geometry_msgs/Twist.h>

#define B 0.1
#define R 0.03

ros::Publisher pubL, pubR;

double calc_wL(double v, double w) {
	double wL = (v - B*w/2) / R;
	return wL;
}

double calc_wR(double v, double w) {
	double wR = (v + B*w/2) / R;
	return wR;
}

void callback(const geometry_msgs::TwistConstPtr &msg) {
	std_msgs::Int16 speedL, speedR;
	int wL, wR;
	wL = calc_wL(msg->linear.x, msg->angular.z);
	wR = calc_wR(msg->linear.x, msg->angular.z);
	
	ROS_INFO("wL: %d, wR: %d", wL, wR);
	
	speedL.data = wL * 8;
	if(speedL.data > 255) speedL.data = 255;
	else if(speedL.data < -255) speedL.data = -255;
	else if(speedL.data > -128 && speedL.data < 128) speedL.data = speedL.data * 16;
	speedR.data = wR * 8;
	if(speedR.data > 255) speedR.data = 255;
	else if(speedR.data < -255) speedR.data = -255;
	else if(speedR.data > -128 && speedR.data < 128) speedR.data = speedR.data * 16;
	
	ROS_INFO("sL: %d, sR: %d", speedL.data, speedR.data);
	
	pubL.publish(speedL);
	pubR.publish(speedR);
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "motor_controller");
    ros::NodeHandle node;

	pubL = node.advertise<std_msgs::Int16>("mega_blue_bot/speedL", 1);
	pubR = node.advertise<std_msgs::Int16>("mega_blue_bot/speedR", 1);

	ros::Subscriber sub = node.subscribe("cmd_vel", 1, callback);

	ros::spin();
}