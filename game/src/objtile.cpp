#include "../lib/objtile.hpp"

ObjTile::ObjTile(float x,float y, SpriteGame sprite) : GameObj(x,y,32,32){
    this->sprite = sprite;
    //this->mask = mask;
}

void ObjTile::render(){
    sprite.DrawSprite(box);
    //DrawRectangleRec(mask,WHITE);
}

void ObjTile::update(){

}

bool ObjTile::isEqual(GameObj* gameobj){
    return (dynamic_cast<ObjTile*>(gameobj));
}