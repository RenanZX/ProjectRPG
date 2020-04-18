#ifndef OBJTILE_H
#define OBJTILE_H

#include "GameObj.hpp"

class ObjTile : public GameObj{
public:
  ObjTile(float x,float y, SpriteGame sprite);
  void render();
  void update();
  static bool isEqual(GameObj* gameobj);
};

#endif