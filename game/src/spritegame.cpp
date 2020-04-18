#include "../lib/spritegame.hpp"

SpriteGame::SpriteGame(){
    
}

SpriteGame::SpriteGame(const char* path_sheet, Rectangle rect){
    sprites = LoadTexture(path_sheet);
    this->rect = rect;
    this->pathsheet = path_sheet;
}

void SpriteGame::SetSpriteSheet(const char* path){
     sprites = LoadTexture(path);
     pathsheet = path;
}

const char* SpriteGame::getSpriteSheet(){
    return pathsheet;
}

void SpriteGame::setRectSprite(Rectangle rect){
   this->rect = rect;
}

Rectangle SpriteGame::getRectSprite(){
    return this->rect;
}

void SpriteGame::DrawSprite(Rectangle rectr){
    DrawTexturePro(sprites,rect,rectr,Vector2{0,0},0,RAYWHITE);
}

void SpriteGame::DrawfillSpriteRec(Rectangle rectr){
    //terminar amanha
    for(int i=0;i<(int)rectr.height;i+=32){
        for(int j=0;j<(int)rectr.width;j+=32){
            DrawTextureRec(sprites,rect,Vector2{rectr.x+j,rectr.y+i},RAYWHITE);
        }
    }
    //DrawTexturePro(sprites,rect,);
    //DrawTextureQuad(sprites,Vector2{0.32,0.32},Vector2{20,20},rectr,RAYWHITE);
}