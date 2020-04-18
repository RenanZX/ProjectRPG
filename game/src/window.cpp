#include "../lib/window.hpp"

Window::Window(float x,float y, SpriteGame sprite) : GameObj(x,y,32,32){
    this->sprite = sprite;
}

void Window::render(){
    sprite.DrawSprite(box);
    //DrawRectangleRec(mask,WHITE);
}

void Window::update(){

}

bool Window::isEqual(GameObj* gameobj){
    return (dynamic_cast<Window*>(gameobj));
}