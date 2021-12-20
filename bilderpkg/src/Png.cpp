#include "bilderpkg/Png.h"
#include <sstream>

//IMPORTANT: include classloader header for the pragma-function
#include "class_loader/class_loader.hpp"
   
//initialise the values of the pragmafunction
//CLASS_LOADER_REGISTER_CLASS(classname/derived class,interface/base class)
CLASS_LOADER_REGISTER_CLASS(Png,Bild);

Png::Png(){
    bild_b = 10;
    bild_h = 10;
}

std::stringstream Png::show() {
    std::stringstream sstream;
    for (int i = 0; i < bild_h; i++) {
        for (int i = 0; i < bild_b; i++) {
            sstream<<"|Schwarz";
        }
        sstream<<"|" << std::endl;
    }
    return sstream;
}

