#include "../lib/cenarycity.hpp"

CenaryCity::CenaryCity(const char* pathtiles) : Cenary(pathtiles){
    
}

SpriteGame CenaryCity::getSpriteFloor(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{0,32*cenary,32,32});
    return *sprite;
}

SpriteGame CenaryCity::getSpriteCeilFull(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{32*9,32*cenary,32*2,32*3});
    return *sprite;
}

SpriteGame CenaryCity::getSpriteWall(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{32,32*cenary,32,32});
    return *sprite;
}

SpriteGame CenaryCity::getSpriteWallEd(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{32*2,32*cenary,32,32});
    return *sprite;
}

SpriteGame CenaryCity::getSpriteCeilWhiteEd(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{32*3,32*cenary,32,32});
    return *sprite;
}

SpriteGame CenaryCity::getSpriteCeilDarkEd(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{32*4,32*cenary,32,32});
    return *sprite;
}

SpriteGame CenaryCity::getSpriteDoorEd(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{32*5,32*cenary,32,32});
    return *sprite;
}

SpriteGame CenaryCity::getSpriteWindowEd(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{32*6,32*cenary,32,32});
    return *sprite;
}

SpriteGame CenaryCity::getSpriteInnBoard(int cenary){
    SpriteGame* sprite = new SpriteGame(pathtiles,Rectangle{32*7,32*cenary,32,32});
    return *sprite;
}
