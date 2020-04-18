#ifndef SPRITEGAME_H
#define SPRITEGAME_H

#include <raylib.h>
#include "constants.hpp"

class SpriteGame{
  private:
    Texture2D sprites;
    Rectangle rect;
    const char* pathsheet;
  public:
    SpriteGame();
    SpriteGame(const char* path_sheet, Rectangle rect);
    void SetSpriteSheet(const char* path);
    const char* getSpriteSheet();
    void setRectSprite(Rectangle rect);
    Rectangle getRectSprite();
    
    void DrawSprite(Rectangle rectr);
    void DrawfillSpriteRec(Rectangle rectr);
};

#endif