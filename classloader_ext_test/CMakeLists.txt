cmake_minimum_required(VERSION 2.8.3)
project(classloader_ext_test)

find_package(   catkin REQUIRED COMPONENTS
                roscpp
                std_msgs
                actionlib actionlib_msgs
                message_generation
                class_loader
                ## Impoted ROS-Pkg with exported librarys
                bilderpkg
    )

catkin_package(
    INCLUDE_DIRS include
    LIBRARIES classloader_ext_test
    ##create dependency to the package
    CATKIN_DEPENDS std_msgs roscpp message_runtime bilderpkg
    DEPENDS system_lib
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_sendBild src/sendBild.cpp)
target_link_libraries(${PROJECT_NAME}_sendBild ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_sendBild publisher_generate_messages_cpp)
add_executable(${PROJECT_NAME}_printBild src/printBild.cpp)
target_link_libraries(${PROJECT_NAME}_printBild ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_printBild publisher_generate_messages_cpp)

