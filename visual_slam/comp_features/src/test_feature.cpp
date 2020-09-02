#include <ros/ros.h>
#include <comp_features/utils.hpp>
#include <comp_features/feature_types.hpp>
#include <comp_features/feature_abstract.hpp>

using namespace comp_feature;

namespace{
    std::string file_1 = "";
    std::string file_2 = "";
   
}



int main(int argc, char** argv){
    ros::init(argc, argv, "test_feature_node");
    ros::NodeHandle nh_;


    orb_feature orb_object;  
    


    while(ros::ok()){
        ros::spinOnce();
    }

    return 0;
}





