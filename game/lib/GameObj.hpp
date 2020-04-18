#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <raylib.h>
#include "spritegame.hpp"
#include <iostream>

using namespace std;

class GameObj{
    protected:
      Rectangle box;
      Rectangle mask;
      SpriteGame sprite;
      Rectangle colisionBox;
    public:
       GameObj(float x, float y, float width, float height);
       GameObj();
       ~GameObj();
       
       virtual void SetSprite(SpriteGame sprite);
       virtual SpriteGame getSprite();

       virtual void ScaleBox(float scale);

       virtual void SetBox(Rectangle box);
       virtual Rectangle getBox();

       virtual void SetMask(Rectangle mask);
       virtual Rectangle getMask();

       virtual void UpdateMask();
       
       virtual void update();
       virtual void render();
       static bool isEqual(GameObj* gameobj);
       virtual bool NotifyCollision(GameObj* gameobj);
};

#endif