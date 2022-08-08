//Ros Default Header File
#include "ros/ros.h"
//flame_msg message file header
//header file is automatically created when building the package

#include "flame_detect/flame_msg.h"

int main(int argc, char **argv){//Node main function
    ros::init(argc,argv,"topic_publisher");//initialize node name
    ros::NodeHandle nh;//node handle declaration for communication with ros system


    //declare publisher, create publisher 'ros_tutorial pub' using flame_msg\
    //message file from the flame_detect package. topic name is
    //flame_msg and the size of the publisher queue is set to 100
    ros::Publisher flame_detect_pub=nh.advertise<flame_detect::flame_msg>("flame_detect_msg",100);

    //set the loop period. 10 refers to 10 HZ and the main loop repeats at 0.1 sec intervals
    ros::Rate loop_rate(10);

    flame_detect::flame_msg msg;

    int count =0;

    while(ros::ok())
    {
        msg.stamp=ros::Time::now();//save current time in the stamp of msg
        msg.data=count;//save the count value in the data of msg

        ROS_INFO("send msg=%d", msg.stamp.sec);//print stam.sec message

        ROS_INFO("send msg=%d", msg.stamp.nsec);//print stamp.nsec mssage
        ROS_INFO("send msg=%d", msg.data);//print data message

        flame_detect_pub.publish(msg);//publsih msg message
        loop_rate.sleep();//goes to sleep according to the loop rate defined above

        ++count;
    }

return 0;

}
