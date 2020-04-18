#include "../lib/ceiltile.hpp"

CeilTile::CeilTile(float x,float y, SpriteGame sprite) : GameObj(x,y,32,32){
    this->sprite = sprite;
    //this->mask = mask;
}

void CeilTile::render(){
    sprite.DrawSprite(box);
    //DrawRectangleRec(mask,WHITE);
}

void CeilTile::update(){

}

bool CeilTile::isEqual(GameObj* gameobj){
    return (dynamic_cast<CeilTile*>(gameobj));
}