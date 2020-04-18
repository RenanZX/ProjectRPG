#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "constants.hpp"
#include <raylib.h>

class Controller {
public:
  int getDir();
  int getAction();
};

#endif