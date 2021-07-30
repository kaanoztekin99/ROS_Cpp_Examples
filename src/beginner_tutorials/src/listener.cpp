#include "ros/ros.h"
//We included our default ros header file in our project.
#include "std_msgs/String.h"
//We have included the header file of the message we will use. 


void callChatterFunc(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("Subscriber received the message: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // We already described init function in our publisher file and here we did the same thing for subscriber node
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  /*
   - The subscribe() call is how you tell ROS that you want to receive messages on a given topic. 
   - This invokes a call to the ROS master node, which keeps a registry of who is publishing and who is subscribing. 
   - The second parameter to the subscribe() function is the size of the message queue.
   
  */
   
  ros::Subscriber sub = n.subscribe("chatter", 1000, callChatterFunc);
  
  /*
   - We called a function as an argument inside the function. This situation is called callback. 
   - ros::spin() will enter a loop, pumping callbacks.  
   - ros::spin() will exit when Ctrl-C is pressed, or the node is shutdown by the master.
  */
  ros::spin();

  return 0;
}
