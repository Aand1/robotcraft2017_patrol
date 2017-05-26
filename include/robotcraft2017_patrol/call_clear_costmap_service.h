#ifndef CALL_CLEAR_COSTMAP_SERVICE_H_
#define CALL_CLEAR_COSTMAP_SERVICE_H_
#include <nav_core/recovery_behavior.h>
#include <costmap_2d/costmap_2d_ros.h>
#include <tf/transform_listener.h>
#include <ros/ros.h>
//#include <costmap_2d/costmap_layer.h>

namespace call_clear_costmap_service{
  /**
   * @class CallClearCostmapService
   * @brief A recovery behavior that calls the move_base clear costmap service.
   */
  class CallClearCostmapService : public nav_core::RecoveryBehavior {
    public:
      /**
       * @brief  Constructor, make sure to call initialize in addition to actually initialize the object
       */
      CallClearCostmapService();

      /**
       * @brief  Initialization function for the CallClearCostmapService recovery behavior
       */
      void initialize(std::string name, tf::TransformListener* tf, 
          costmap_2d::Costmap2DROS* global_costmap, costmap_2d::Costmap2DROS* local_costmap);

      /**
       * @brief  Run the CallClearCostmapService recovery behavior. 
       */
      void runBehavior();

    private:
      costmap_2d::Costmap2DROS* global_costmap_, *local_costmap_;
      std::string name_;
      tf::TransformListener* tf_;
      bool initialized_;
  };
};
#endif  