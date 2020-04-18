#include "../lib/GameObj.hpp"

GameObj::GameObj(float x, float y, float width, float height) {
    this->box.x = x;
    this->box.y = y;
    this->box.width = width;
    this->box.height = height;
    this->mask = box;
}

GameObj::GameObj(){

}

GameObj::~GameObj(){
    
}

void GameObj::SetSprite(SpriteGame sprite){
    this->sprite = sprite;
}

void GameObj::SetBox(Rectangle box){
    this->box = box;
    this->mask = box;
}

SpriteGame GameObj::getSprite(){
    return sprite;
}

Rectangle GameObj::getBox(){
    return this->box;
}

void GameObj::ScaleBox(float scale){
    box.width*=scale;
    box.height*=scale;
    mask.width *= scale;
    mask.height *= scale;
}

void GameObj::SetMask(Rectangle mask){
    this->mask = mask;
}

Rectangle GameObj::getMask(){
    return mask;
}

void GameObj::UpdateMask(){
    mask.x = box.x+5;
    mask.y = box.y;
}

bool GameObj::NotifyCollision(GameObj* gameobj){
    Rectangle mask2 = gameobj->getMask();
    bool collision = CheckCollisionRecs(mask,mask2);
    if(collision){
        colisionBox = mask2;
    }

    return collision;
}

void GameObj::update(){

}

void GameObj::render(){
    sprite.DrawSprite(box);
}