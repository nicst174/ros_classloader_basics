# Implementation of the classloader
## Explanation
CMake:
- First you need to find the class_loader and the new created package you want to load dynamically.
- Then add the dependancy to catkin_package.

Source files:

This is just a basic programm, which sends (to ```printBild```) eihter a Jpeg or a Png, but they are already decoded to a string by the sender ```sendBild```.
For the explanation of how to use the class_loader, either look in the sendBild.cpp file or on [the offical ROS website](http://wiki.ros.org/class_loader#Interface)
