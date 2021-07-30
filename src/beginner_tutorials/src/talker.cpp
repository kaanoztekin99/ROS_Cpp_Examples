#include "ros/ros.h"
//We included our default ros header file in our project. 
#include "std_msgs/String.h"
//We have included the header file of the message we will use. 
#include <sstream>


int main(int argc, char **argv)
{
  /* 
   - The ros::init() function needs to see argc and argv so that it can perform any ROS arguments and name remapping that were provided at the command line. 
   - The third argument to init() is the name of the node. We need to define the name of the node we are going to start. */
  ros::init(argc, argv, "talker");


  // NodeHandle is the main access point to communications with the ROS system.
  ros::NodeHandle n;
  
  /*
   - We need to create a topic. We used advertise method with NodeHandle.
   - The advertise() function is how you tell ROS that you want to publish on a given topic name.
   - This invokes a call to the ROS master node, which keeps a registry of who is publishing and who is subscribing. 
   - The second parameter is the size of the message queue used for publishing messages.
   */

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  // Our topic name is = chatter

  ros::Rate loop_rate(10);
  // We set our operating speed to 10Hz. 
  
  
  // A count of how many messages we have sent.
   int count = 0;
   
  // Continue as long as there are no errors or disconnections 
  while (ros::ok())
  {
    
    // This is a message object. You stuff it with data, and then publish it.
     
    std_msgs::String msg;

    std::stringstream ss;
    ss << "Kaan(Publisher) sent the message number: " << count;
    msg.data = ss.str();
    
    // Here is our ros print function that we use to see the data and the message. 
    ROS_INFO("%s", msg.data.c_str());

    
    // The publish() function is how you send messages. The parameter is the message object.

    chatter_pub.publish(msg);

    ros::spinOnce();
    
    // We used sleep() method to ensure the continuity of the working speed at the Hz we set as stable. 
    loop_rate.sleep();
    ++count;
  }


  return 0;
}
