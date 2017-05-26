#include <robotcraft2017_patrol/call_clear_costmap_service.h>
#include <pluginlib/class_list_macros.h>
#include <std_srvs/Empty.h>

//register this as a RecoveryBehavior plugin
PLUGINLIB_DECLARE_CLASS(call_clear_costmap_service, CallClearCostmapService, call_clear_costmap_service::CallClearCostmapService, nav_core::RecoveryBehavior)

namespace call_clear_costmap_service {
CallClearCostmapService::CallClearCostmapService(): global_costmap_(NULL), local_costmap_(NULL), 
  tf_(NULL), initialized_(false) {} 

void CallClearCostmapService::initialize(std::string name, tf::TransformListener* tf,
    costmap_2d::Costmap2DROS* global_costmap, costmap_2d::Costmap2DROS* local_costmap){
  if(!initialized_){
    name_ = name;
    tf_ = tf;
    global_costmap_ = global_costmap;
    local_costmap_ = local_costmap;
    initialized_ = true;
  }
  else{
    ROS_ERROR("You should not call initialize twice on this object, doing nothing.");
  }
}

void CallClearCostmapService::runBehavior(){
  if(!initialized_){
    ROS_ERROR("This object must be initialized before runBehavior is called.");
    return;
  }

  ROS_WARN("Calling clear costmap service to unstuck robot: Be careful!");
  
  std_srvs::Empty srv;
  
  //if needed:
  //std::string ns = ros::this_node::getNamespace();

  ros::service::call("move_base/clear_costmaps", srv);  //works even with a set namespace
}

};
