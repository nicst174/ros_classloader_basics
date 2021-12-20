#include "bilderpkg/Bild.h"                                          //Imported Interface for the Plugin
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <boost/smart_ptr/shared_ptr.hpp>
#include <sstream>
#include <string>
#include "class_loader/class_loader.hpp"
#include <vector>
#include <boost/shared_ptr.hpp>
#include <iostream>

int main(int argc, char **argv){
    ros::init(argc, argv, "sendBild");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);
    int count = 0;
    //CLASSLOADER init
    class_loader::ClassLoader loader("libbilderpkg.so");             //load shared library in folder ${WORKSPACE_FOLDER}/devel/lib
    //loader.loadLibrary();
    std::vector<std::string> classes = loader.getAvailableClasses<Bild>();      // create a list of available/loaded classes
    int i = classes.size();
    ROS_INFO("%d",i);
    ROS_INFO("%d",loader.isLibraryLoaded());
    //CLASSLOADER create instance/ object from class
    boost::shared_ptr<Bild> plugin = loader.createInstance<Bild>(classes[1]);   //create pointer of an object from class in () which inherited from <> --> IMPORTANT: Pragma in Classes .cpp file!! 
    while(ros::ok()){
        std_msgs::String msg;
        std::stringstream ss = plugin->show();                                  //call a function from the created object
        ss<<count;
        msg.data = ss.str();
        ROS_INFO_STREAM("Picture "<<std::to_string(count)<<" send.");
        chatter_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
