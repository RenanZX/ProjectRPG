#ifndef CEILTILE_H
#define CEILTILE_H

#include "GameObj.hpp"

class CeilTile : public GameObj{
public:
  CeilTile(float x,float y, SpriteGame sprite);
  void render();
  void update();
  static bool isEqual(GameObj* gameobj);
};

#endif