#ifndef TREE_H
#define TREE_H

#include "spritegame.hpp"
#include "GameObj.hpp"

class Tree: public GameObj{
public:
  Tree(float x,float y, SpriteGame sprite);
  void update();
  void render();
  bool isEqual(GameObj* gameobj);
};

#endif