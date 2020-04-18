#include "../lib/door.hpp"

Door::Door(float x,float y, SpriteGame sprite) : GameObj(x-15,y-25,32*1.8,32*1.8){
    this->sprite = sprite;
}

void Door::render(){
    sprite.DrawSprite(box);
    //DrawRectangleRec(mask,WHITE);
}

void Door::update(){

}

bool Door::isEqual(GameObj* gameobj){
    return (dynamic_cast<Door*>(gameobj));
}