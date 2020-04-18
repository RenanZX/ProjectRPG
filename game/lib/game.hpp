#ifndef GAME_H
#define GAME_H

/*raylib bibs*/
#include <raylib.h>
#include <raymath.h>

/*player, sprite e Gameobj*/
#include "player.hpp"
#include "spritegame.hpp"
#include <vector>
#include <iostream>
#include "GameObj.hpp"

/*include tiles*/
#include "floortile.hpp"
#include "walltile.hpp"
#include "ceiltile.hpp"
#include "objtile.hpp"
#include "ceil.hpp"

/*include objects e obstacles*/
#include "Tree.hpp"
#include "door.hpp"
#include "window.hpp"

#include "cenarycity.hpp"

using namespace std;

class Game{
  private:
    const int screenWidth = 640;
    const int screenHeight = 480;
    Camera2D camera;
    Player * player;
    vector<GameObj*> Floor; /*Chao*/
    vector<GameObj*> Obstacles; /*obstaculos*/
    vector<GameObj*> Objects; /*Objetos*/
    int mapwidth;
    int mapheight;
    
    void GenerateCity(const char* path);
    void GenerateBar(const char* path);
    void GenerateFreeArea(const char* path);
    void GenerateInn(const char* path);

    void GenerateWorld(const char* path, int type);
    void CalculateCollisions();
  public:
    void update();
    void render();
    void run();
};

#endif