#include "ros_Classloader_Test/Jpeg.h"
#include <sstream>
#include <iostream>

//IMPORTANT: include classloader header for the pragma-function
#include "class_loader/class_loader.hpp"

//initialise the values of the pragmafunction
//CLASS_LOADER_REGISTER_CLASS(classname/derived class,interface/base class)
CLASS_LOADER_REGISTER_CLASS(Jpeg,Bild);

Jpeg::Jpeg(){
    bild_b = 5;
    bild_h = 10;
}
std::stringstream Jpeg::show() {
    std::stringstream sstream;
    sstream<<std::endl;
    for (int i = 0; i < bild_h; i++) {
         for (int i = 0; i < bild_b; i++) {
             sstream<<"|Bunt";
         }
         sstream<<"|" << std::endl;
     }
    return sstream;
};
