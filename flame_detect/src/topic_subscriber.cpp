//ROS default header file

#include "ros/ros.h"
//flame_msg file header
//header automatically created when building package
#include "flame_detect/flame_msg.h"

//Message callback function. this function is called when a topic
//message named flame_msg is received. As an input message, the
//flame_msg of flame_detect package is received

void msgCallback(const flame_detect::flame_msg::ConstPtr& msg)
{
ROS_INFO("send msg=%d", msg->stamp.sec);//print stam.sec message
ROS_INFO("send msg=%d", msg->stamp.nsec);//print stamp.nsec mssage
ROS_INFO("send msg=%d", msg->data);//print data message
}

int main(int argc, char **argv)//node main function
{
ros::init(argc, argv,"topic_subscriber");//initialize

ros::NodeHandle nh; //Node handle declaration for communication with ROS

//declaere subscriber, create subscriber 'flame_detect_sub' using flame_msg
//message file from the flame_detect package
//topic name is flame_msg and the size of the publisher queue is set to 100
ros::Subscriber flame_detect_sub=nh.subscribe("flame_detect_msg", 100 , msgCallback);

//function for calling callback function, waiting for a message to be
//received, and executing a callback function when it is received
ros::spin();

return 0;
}


