#ifndef Png_h
#define Png_h

#include "Bild.h"
#include <sstream>

struct Png: public Bild {
    Png();
    std::stringstream show() override;
    ~Png() = default;
};

#endif
