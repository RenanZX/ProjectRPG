#include "../lib/ceil.hpp"

Ceil::Ceil(float x,float y, SpriteGame sprite) : GameObj(x,y-2*TILE_SIZE,32*5,32*4){
    this->sprite = sprite;
}

void Ceil::render(){
    sprite.DrawSprite(box);
    //DrawRectangleRec(mask,WHITE);
}

void Ceil::update(){

}

bool Ceil::isEqual(GameObj* gameobj){
    return (dynamic_cast<Ceil*>(gameobj));
}