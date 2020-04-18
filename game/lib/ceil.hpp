#ifndef CEIL_H
#define CEIL_H

#include "spritegame.hpp"
#include "GameObj.hpp"

class Ceil: public GameObj
{
public:
  Ceil(float x,float y, SpriteGame sprite);
  void update();
  void render();
  bool isEqual(GameObj* gameobj);
};

#endif