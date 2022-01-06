# Plugin-Library for the classloader
## Explanation
Sourcefiles:
- The class_loader has to recognize the different classes you want to export. That means, you have to include the class_loader header and define the macrofunction ´´´CLASS_LOADER_REGISTER_CLASS´´´ in the source files and define the base- and derived classname.
CMake:
- First you need to find the package class_loader. 
- Then add a ´´´SHARED´´´ library (.so) or else the class_loader cant load it. 
> And it is important to add the header files here.
- Install the library and header in the catkin-related folder -->devel/lib 
