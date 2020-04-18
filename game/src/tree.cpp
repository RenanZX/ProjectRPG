#include "../lib/tree.hpp"

Tree::Tree(float x,float y, SpriteGame sprite) : GameObj(x,y,32*3,32*3){
    this->sprite = sprite;
    this->mask = Rectangle{x+35,y+50,32,32*1.5};
}

void Tree::render(){
    sprite.DrawSprite(box);
    //DrawRectangleRec(mask,WHITE);
}

void Tree::update(){

}

bool Tree::isEqual(GameObj* gameobj){
    return (dynamic_cast<Tree*>(gameobj));
}