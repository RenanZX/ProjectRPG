#ifndef PLAYER_H
#define PLAYER_H

#include "constants.hpp"
#include "controller.hpp"
#include <raylib.h>
#include "GameObj.hpp"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Player : public GameObj {
private:    
    int maxInd = 8;
    float frametime = 0.0f;
    int ind = 0;
    Rectangle downplayer;
    Rectangle upplayer;
    Rectangle leftplayer;
    Rectangle rightplayer;
    Controller controller;
    float speed = 3;
    float normalspeed = 3;
    float runningspeed = 8;
    int ColisionArea = 0;
    float diffx = 0;
    float diffy = 0;

    bool right_dir = true;
    bool left_dir = true;
    bool up_dir = true;
    bool down_dir = true;

    int AreaLocked(Vector2 x);

    void FreeMove(Vector2 p1,Vector2 p2, Vector2 p3, Vector2 p4);

    void ResetDirs();
public:
    Player(float x,float y,float width, float height, SpriteGame sprite);
    void CollidedWall();
    void update();
    void render(Camera2D cam);
};

#endif