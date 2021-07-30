#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"

// WRITING A SERVICE NODE


bool calculateSum(beginner_tutorials::AddTwoInts::Request  &req,
         beginner_tutorials::AddTwoInts::Response &res)
{
  // We have a and b variables from srv file
  res.sum = req.a + req.b;
  ROS_INFO("Request: x=%ld, y=%ld\n",req.a,req.b);
  ROS_INFO("Sending back response: [%ld]\n",res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", calculateSum);
  ROS_INFO("Service Server is ready to add two ints.");
  
  ros::spin();

  return 0;
}
