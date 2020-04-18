#ifndef FLOORTILE_H
#define FLOORTILE_H

#include "GameObj.hpp"

class FloorTile : public GameObj {
public:
  FloorTile(float x,float y, SpriteGame sprite);
  void render();
  void update();
  static bool isEqual(GameObj* gameobj);
};

#endif