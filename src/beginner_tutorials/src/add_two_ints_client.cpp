// WRITING A CLIENT NODE
// Our client will send two arguments to sum them in server and send it back

#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>
// we included cstdlib to use atoll function

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3)
  {
    //If our total number of arguments is not 3, let's inform the user. 
    ROS_INFO("Usage: add_two_ints_client X Y");
    ROS_INFO("X and Y both integer numbers");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  beginner_tutorials::AddTwoInts srv;
  // our argv[0] = shows itself so we start from index 1 to get integers
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  // We convert our arguments to the integer with atoii
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
