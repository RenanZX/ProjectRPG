#ifndef WINDOW_H
#define WINDOW_H

#include "spritegame.hpp"
#include "GameObj.hpp"

class Window : public GameObj
{
public:
  Window(float x,float y, SpriteGame sprite);
  void update();
  void render();
  bool isEqual(GameObj* gameobj);
};

#endif