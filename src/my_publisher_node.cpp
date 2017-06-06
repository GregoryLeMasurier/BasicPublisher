#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char*argv[]){

ros::init(argc, argv, "my_publisher");
ros::NodeHandle n;
ros::Publisher pub = n.advertise <geometry_msgs::Twist>("my_topic",1000);
ros::Rate loop_rate(10);

while(ros::ok()){
geometry_msgs::Twist msg;
msg.linear.x = 5;
msg.linear.y = 10;
msg.linear.z = 15;

msg.angular.x = 1;
msg.angular.y = 2;
msg.angular.z = 3;

pub.publish(msg);
ros::spinOnce();
loop_rate.sleep();
}
return 0;
}
