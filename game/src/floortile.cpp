#include "../lib/floortile.hpp"

FloorTile::FloorTile(float x,float y, SpriteGame sprite) : GameObj(x,y,TILE_SIZE,TILE_SIZE)
{
    this->sprite = sprite;
}

void FloorTile::update(){

}

void FloorTile::render(){
    sprite.DrawSprite(box);
}

bool FloorTile::isEqual(GameObj* gameobj){
    return (dynamic_cast<FloorTile*>(gameobj));
}
