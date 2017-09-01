#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/Int16MultiArray.h>
#include "robotcraft2017_patrol/graph.h"

#define GRAPH_DIMENSION 12

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


//Global variables to access within the callbacks:
int robot_id;
ros::Publisher *comm_pub_ptr;

//variables for logging:
FILE *results;
std::string file_path;
int goal_vertex;


//Callback triggered everytime this robot reaches a goal (or aborts its goals):
void goalDoneCallback(const actionlib::SimpleClientGoalState &state, const move_base_msgs::MoveBaseResultConstPtr &result){
	
	if(state.state_ == actionlib::SimpleClientGoalState::SUCCEEDED){
 		ROS_INFO("Robot %d successfully reached goal.", robot_id);
                write_visit_to_file (results, file_path, robot_id, ros::Time::now().toSec(), goal_vertex);
	}else{
 		ROS_INFO("Robot %d could not reach goal. Gave up!", robot_id);
	}
}


//Callback triggered everytime that this robot's goal becomes active:
void goalActiveCallback(){	
    ROS_INFO("Robot %d goal is active.", robot_id);
}


//Callback triggered continuously when a goal is given to the robot:
void goalFeedbackCallback(const move_base_msgs::MoveBaseFeedbackConstPtr &feedback){ 
    //ROS_INFO("Robot %d is moving towards a goal.", robot_id);
}


//Callback triggered everytime you receive a msg from another robot:
void ReceiveCommunicationsCB(const std_msgs::Int16MultiArray::ConstPtr& msg) { 

    //Remeber that the format of this message is an array of integers (Int16MultiArray):
    int other_robot_id = msg->data[0];
    int other_robot_vertex = msg->data[1];
    
    //filter out your own messages:
    if(robot_id != other_robot_id){ 
        ROS_INFO("Robot %d received this message from robot %d: [%d,%d]", robot_id, other_robot_id, msg->data[0], msg->data[1]);
    }
}


//A utility function for publishing a message in the "/communication" topic
void publish_message(int vertex){
    
    //In this example we will publish an array of 2 integers like this: [robot_id, vertex]
    //feel free to modify this function to suit your needs (e.g. publish more information, etc.)
    
    std_msgs::Int16MultiArray msg;
    msg.data.clear();
    msg.data.push_back(robot_id);
    msg.data.push_back(vertex);
    comm_pub_ptr->publish(msg);
    ROS_INFO("Robot %d published: [%d,%d]", robot_id, msg.data[0], msg.data[1]);
}



//Example: Run as robot_2: "rosrun robotcraft2017_patrol patrolbot robot_id:=2"
int main(int argc, char** argv){ 
    
  // ROS Setup:
  ros::init(argc, argv, "patrolbot");
  ros::NodeHandle n;
  ros::NodeHandle p("~"); //for private parameters
  
  //Parsing the private parameters passed on to the node:
  p.param("robot_id", robot_id, 0); //if you don't pass the "robot_id" argument, it will default as "0".
  
  std::stringstream id_stream;
  id_stream << robot_id;
  std::string move_base_client = "robot_" + id_stream.str() + "/move_base";
  MoveBaseClient ac(move_base_client.c_str(), true);

  //wait for the action server to become ready:
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  
  //A small sleep of 2.0 seconds for synchronization:
  ros::Duration(2.0).sleep();

  //Define a publisher to the "/communication" topic as an array of integers (to send data to other robots):
  ros::Publisher comm_pub = n.advertise<std_msgs::Int16MultiArray>("/communication", 100);
  comm_pub_ptr = &comm_pub;
  
  //Define a "/communication" subscriber (to receive data from other robots) in the "/communication" topic:
  ros::Subscriber comm_sub = n.subscribe<std_msgs::Int16MultiArray>("/communication", 100, ReceiveCommunicationsCB ); 
  
  //Navigation goal object:
  move_base_msgs::MoveBaseGoal goal;
  
  //Structure with the Graph Info:
  vertex_set *graph;
  graph = new vertex_set [GRAPH_DIMENSION];
  load_graph(graph);    //have a look at "graph.cpp" to see what you've just loaded.

  //x,y targets
  double target_x;                  //in m
  double target_y;                  //in m
  double target_angle_yaw = 0.0;    //in rads
  int target_vertex;
  
  //add your initializations here:
  //........
  //........
  file_path = get_log_file(results, robot_id);
  results=fopen (file_path.c_str(),"a"); //open log file
  fprintf(results, "robot_id,time visited;vertex\n"); //file Header
  fclose(results);   
  
  //A simple example of defining navigation goals based on the graph:
  if (robot_id==0){//send "robot_0" from vertex 4 to vertex 5
     goal_vertex = 4;
     graph[4].visits++;    //mark vertex 4 as visited once
     target_vertex = 5;
        
  }else if (robot_id==1){//send "robot_1" from vertex 11 to vertex 10
     goal_vertex = 11;
     graph[11].visits++;    //mark vertex 11 as visited once
     target_vertex = 10;       
        
  }else{//send "robot_2" from vertex 3 to vertex 7
     goal_vertex = 3;
     graph[3].visits++;    //mark vertex 3 as visited once
     target_vertex = 7;   
  }
  
  write_visit_to_file (results, file_path, robot_id, ros::Time::now().toSec(), goal_vertex); //initial vertex 
  
  target_x = graph[target_vertex].x; 
  target_y = graph[target_vertex].y;   
  
  //control variables:
  bool send_goal = true;
  bool example_publish = true;
  ros::Time GoalTime;
  
  ros::Rate loop_rate(50); //explicitly define while loop_rate at 50Hz (this will drastically decrease your CPU load)
  
  
  while(ros::ok()){ 

    if (send_goal){
        //Example of sending a goal:
        goal.target_pose.header.frame_id = "map";
        GoalTime = ros::Time::now();
        goal.target_pose.header.stamp = GoalTime;
        geometry_msgs::Quaternion angle_quat = tf::createQuaternionMsgFromYaw(target_angle_yaw); //A quaternion must be created to send a goal.
        goal.target_pose.pose.position.x = target_x;
        goal.target_pose.pose.position.y = target_y;
        goal.target_pose.pose.orientation = angle_quat;

        ROS_INFO("Sending goal to robot %d.", robot_id);
        ac.sendGoal(goal, boost::bind(&goalDoneCallback, _1, _2), boost::bind(&goalActiveCallback), boost::bind(&goalFeedbackCallback, _1));
        
        send_goal = false;  //only sends goal once.
    }
    
    //A basic example: publishing a message in the "/communication" topic 10 seconds after sending a goal
    if( example_publish && ros::Time::now() > GoalTime + ros::Duration(10.0) ){
        publish_message(target_vertex);
        example_publish = false; //only publishes once.
    }
    
    ros::spinOnce(); //needed to make sure that all your callbacks are triggered.
    loop_rate.sleep();
  }
  
  close_log_file(results);
  delete graph;
  return 0;
}
