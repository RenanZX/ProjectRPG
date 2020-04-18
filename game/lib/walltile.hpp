#ifndef WALLTILE_H
#define WALLTILE_H

#include "GameObj.hpp"
#include "spritegame.hpp"

class WallTile : public GameObj {
   
   public:
    WallTile(float x,float y, SpriteGame sprite);
    static bool isEqual(GameObj* gameobj);
    void render();
    void update();
};

#endif