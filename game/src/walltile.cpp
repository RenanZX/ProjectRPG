#include "../lib/walltile.hpp"

WallTile::WallTile(float x,float y, SpriteGame sprite) : GameObj(x,y,32,32){
    this->sprite = sprite;
    //this->mask = mask;
}

void WallTile::render(){
    sprite.DrawSprite(box);
    //DrawRectangleRec(mask,WHITE);
}

void WallTile::update(){

}

bool WallTile::isEqual(GameObj* gameobj){
    return (dynamic_cast<WallTile*>(gameobj));
}