#ifndef Jpeg_h
#define Jpeg_h

#include <sstream>
#include "Bild.h"

struct Jpeg: public Bild{
    Jpeg();
    std::stringstream show() override;
    ~Jpeg() = default;
};

#endif
