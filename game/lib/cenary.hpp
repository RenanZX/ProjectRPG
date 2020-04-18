#ifndef CENARY_H
#define CENARY_H

#include "spritegame.hpp"
#include <raylib.h>

class Cenary{
protected:
   const char* pathtiles;
public:
   Cenary(const char* pathtiles);
};

#endif