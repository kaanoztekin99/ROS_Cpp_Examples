#include<ros/ros.h>
#include<actionlib/server/simple_action_server.h>
#include<beginner_tutorials/FibonacciAction.h>


class FibonacciAction{

	private:
		ros::NodeHandle n;
		
		actionlib::SimpleActionServer<beginner_tutorials::FibonacciAction> as;
		
		beginner_tutorials::FibonacciGoal hedef;
		beginner_tutorials::FibonacciResult sonuc;
		beginner_tutorials::FibonacciFeedback feed_back;
		
	public:
		FibonacciAction();
		//constructor
		~FibonacciAction(void){}
		//destructor
		
		void func(const actionlib::SimpleActionServer<beginner_tutorials::FibonacciAction>::GoalConstPtr& goal);

};


FibonacciAction::FibonacciAction():
as(n,"fibonacci_action",boost::bind(&FibonacciAction::func,this,_1),false){

	as.start();
	//we started our action server
}

void FibonacciAction::func(const actionlib::SimpleActionServer<beginner_tutorials::FibonacciAction>::GoalConstPtr& goal){

	ros::Rate r(1);
	
	feed_back.sequence.clear();
	feed_back.sequence.push_back(0);
	feed_back.sequence.push_back(1);
	
	
	ROS_INFO("Çalışıyor..., Fibonacci dizisi, hedef: %i,başlangıç %i,%i",goal->order,feed_back.sequence[0],feed_back.sequence[1]);
	
	
	
	for(int i=1; i<goal->order;i++){
		feed_back.sequence.push_back(feed_back.sequence[i]+ feed_back.sequence[i-1]);
		as.publishFeedback(feed_back);
	}
	
	sonuc.sequence = feed_back.sequence;
	ROS_INFO("BAŞARILI ! ");
	as.setSucceeded(sonuc);
	
}


int main(int argc,char **argv){

	ros::init(argc,argv,"action_server");
	
	FibonacciAction obj;
	
	ros::spin();
	
	return 0;

}



