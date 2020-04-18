#ifndef DOOR_H
#define DOOR_H

#include "GameObj.hpp"
#include "SpriteGame.hpp"

class Door: public GameObj{
public:
  Door(float x,float y, SpriteGame sprite);
  void update();
  void render();
  bool isEqual(GameObj* gameobj);
};

#endif