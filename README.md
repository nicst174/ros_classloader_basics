# ros_classloader_basics
Basic integration of the ros classloader for the purpose of managing plugins.
## Installation
> Note: This package was created and build with catkin.
1. Clone the reposiory in your src-folder in a ros-workspace, that was created like [this](http://wiki.ros.org/catkin/Tutorials/create_a_workspace).
2. Run catkin_make in your workspace to build the project.
3. Then run the following in seperate windows:
> Note: Don't forget to source a setup-file (e.g. ```source devel/setup.zsh```)
```
roscore
```
```
rosrun classloader_ext_test classloader_ext_test_sendBild
```
```
rosrun classloader_ext_test classloader_ext_test_printBild
```
## Explanation 
Both packages have their own README file and code-commentary, where everything is explained.
