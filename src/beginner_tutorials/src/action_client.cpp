#include<ros/ros.h>
#include<actionlib/client/simple_action_client.h>
#include<actionlib/client/terminal_state.h>
#include<beginner_tutorials/FibonacciAction.h>

int main(int argc,char **argv){

	ros::init(argc,argv,"action_client");
	
	actionlib::SimpleActionClient<beginner_tutorials::FibonacciAction>ac("fibonacci_action",true);
	
	ac.waitForServer();
	
	beginner_tutorials::FibonacciGoal hedef;
	hedef.order = 20;
	
	ac.sendGoal(hedef);
	
	bool limit= ac.waitForResult(ros::Duration(30.0));
	
	if(limit){
	
		actionlib::SimpleClientGoalState state= ac.getState();
		ROS_INFO("İşlem tamamlandı: %s",state.toString().c_str());
	}
	else{
	
		ROS_INFO("İşlem gereken sürede tamamlanamadı !");
	}
	return 0;
}
