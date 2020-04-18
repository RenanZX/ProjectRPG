#ifndef CENARYCITY_H
#define CENARYCITY_H

#include "spritegame.hpp"
#include <vector>
#include "cenary.hpp"

using namespace std;

class CenaryCity : public Cenary{
public:
   CenaryCity(const char* pathtiles);

   SpriteGame getSpriteFloor(int cenary);
   SpriteGame getSpriteWall(int cenary);
   SpriteGame getSpriteWallEd(int cenary);
   SpriteGame getSpriteCeilWhiteEd(int cenary);
   SpriteGame getSpriteCeilDarkEd(int cenary);
   SpriteGame getSpriteCeilFull(int cenary);
   SpriteGame getSpriteDoorEd(int cenary);
   SpriteGame getSpriteWindowEd(int cenary);
   SpriteGame getSpriteInnBoard(int cenary);
};

#endif