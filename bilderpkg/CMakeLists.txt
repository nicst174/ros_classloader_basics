cmake_minimum_required(VERSION 2.8.3)
project(bilderpkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  actionlib actionlib_msgs message_generation
  message_generation
  class_loader
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}  ##deprcated:ros_Classloader_Test now bilderpkg
  CATKIN_DEPENDS message_runtime roscpp rospy std_msgs
  DEPENDS system_lib
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
  )

## create the pkg-library with nessesary files, header + .cpp; created in ${WORSPACE}/devel/lib/lib${PROJECT_NAME} --> here libros_Classloader_Test
add_library(${PROJECT_NAME} SHARED
    src/Jpeg.cpp
    src/Png.cpp
    include/bilderpkg/Bild.h
    include/bilderpkg/Jpeg.h
    include/bilderpkg/Png.h
    )

##mark the include-directory, where the header files are placed
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

##install the packages files in the catkin folder -> devel
install(TARGETS ${PROJECT_NAME}
   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
 )

##install the include-header in the catkin folder include
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
 )
