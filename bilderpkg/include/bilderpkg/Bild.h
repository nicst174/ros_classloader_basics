#ifndef Bild_h
#define Bild_h

#include <sstream>

//Interfaceclass

struct Bild{
    int bild_h;
    int bild_b;
    virtual std::stringstream show() = 0;
    virtual ~Bild() = default;
};
#endif
