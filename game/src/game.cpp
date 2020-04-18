/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "../lib/game.hpp"

void Game::GenerateCity(const char* path){
   Image map = LoadImage(path);
    
   Color* pixels = GetImageData(map);
   float newX;
   float newY;

   //SpriteGame *sprite;

   float width = map.width;
   float height = map.height;
   //const char * sprite_tilehouse_path = "./assets/spritesheet_houses_ed_stages.png";
    //otimizar sistema
   CenaryCity * cenary = new CenaryCity("./assets/spritesheet_city.png");
   int type = 0;
   for(int xx=0;xx<(int)width;xx++){
       for(int yy=0;yy<(int)height;yy++){
           Color pixel = pixels[xx+yy*((int)width)];
           newX = (float)xx * TILE_SIZE;
           newY = (float)yy * TILE_SIZE;
            

           //sprite = new SpriteGame(sprite_tile_path,Rectangle{0,32*2,32,32});
           Floor.push_back(new FloorTile(newX,newY, cenary->getSpriteFloor(type)));
                
           switch (ColorToInt(pixel))
           {
           case 0x5B5B5BFF: // chao
               Floor.push_back(new FloorTile(newX,newY, cenary->getSpriteFloor(3)));
               break;
           case 0x7F7F7FFF:
              Floor.push_back(new FloorTile(newX,newY, cenary->getSpriteFloor(2)));
              break;
           case 0x545454FF:
              Floor.push_back(new FloorTile(newX,newY,cenary->getSpriteFloor(4)));
              break;
           case 0xFFFFFFFF: //parede cenario
               //sprite = new SpriteGame(sprite_tile_path,Rectangle{32,0,32,32});
               Obstacles.push_back(new WallTile(newX,newY, cenary->getSpriteWall(type)));
               break;
           case 0x4800FFFF: //player
               Rectangle boxp;
               boxp = player->getBox();
               boxp.x = xx*TILE_SIZE;
               boxp.y = yy*TILE_SIZE;
               player->SetBox(boxp);
               break;
           case 0xFFD800FF: /*parede edificios */
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{0,32,32,32});
               Obstacles.push_back(new WallTile(newX, newY, cenary->getSpriteWallEd(type)));
               break;
           case 0xC4A300FF: /*telhados dos edificios*/
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{32,32,32,32});
               Objects.push_back(new CeilTile(newX, newY, cenary->getSpriteCeilWhiteEd(type)));
               break;
           case 0x705D00FF:
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{32*2,32,32,32});
               Objects.push_back(new CeilTile(newX, newY, cenary->getSpriteCeilDarkEd(type)));
               break;
           case 0xCEAC00FF:
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{32*8,0,32*2,32*3});
               Objects.push_back(new Ceil(newX, newY, cenary->getSpriteCeilFull(type)));
               break;
           case 0x493C00FF: /*portas*/
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{0,32,32,32});
               Obstacles.push_back(new WallTile(newX, newY, cenary->getSpriteWallEd(type)));
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{32*3,32,32,32});
               Objects.push_back(new Door(newX,newY,cenary->getSpriteDoorEd(type)));
               break;
           case 0x3F3400FF:
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{0,32,32,32});
               Obstacles.push_back(new WallTile(newX, newY, cenary->getSpriteWallEd(type)));
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{32*3,32*2,32,32});
               Objects.push_back(new Door(newX,newY,cenary->getSpriteDoorEd(type)));
               break;
           case 0xE5BF00FF: //Janelas
               //sprite = new SpriteGame(sprite_tilehouse_path, Rectangle{0,32,32,32});
               Obstacles.push_back(new WallTile(newX, newY, cenary->getSpriteWallEd(type)));
               //sprite = new SpriteGame(sprite_tilehouse_path,Rectangle{32*4,32,32,32});
               Objects.push_back(new Window(newX, newY, cenary->getSpriteWindowEd(type)));
               break;
           default:  
               break;
           }
       }
   }

   mapwidth = width;
   mapheight = height;
}

void Game::GenerateBar(const char* path){
   Image map = LoadImage(path);
    
   Color* pixels = GetImageData(map);
   float newX;
   float newY;

   SpriteGame *sprite;

   float width = map.width;
   float height = map.height;
   const char * sprite_tile_path = "./assets/spritesheet_Obj_stages.png"; 
   const char * sprite_tilehouse_path = "./assets/spritesheet_houses_ed_stages.png";

   for(int xx=0;xx<(int)width;xx++){
       for(int yy=0;yy<(int)height;yy++){
           Color pixel = pixels[xx+yy*((int)width)];
           newX = (float)xx * TILE_SIZE;
           newY = (float)yy * TILE_SIZE;

           switch(ColorToInt(pixel)){
              
           }
       }
   }
   
   mapwidth = width;
   mapheight = height;

}

void Game::GenerateInn(const char* path){
   Image map = LoadImage(path);
    
   Color* pixels = GetImageData(map);
   float newX;
   float newY;

   SpriteGame *sprite;

   float width = map.width;
   float height = map.height;
   const char * sprite_tile_path = "./assets/spritesheet_Obj_stages.png"; 
   const char * sprite_tilehouse_path = "./assets/spritesheet_houses_ed_stages.png";

   for(int xx=0;xx<(int)width;xx++){
       for(int yy=0;yy<(int)height;yy++){
           Color pixel = pixels[xx+yy*((int)width)];
           newX = (float)xx * TILE_SIZE;
           newY = (float)yy * TILE_SIZE;

           switch(ColorToInt(pixel)){
              
           }
       }
   }
   
   mapwidth = width;
   mapheight = height;

}

void Game::GenerateFreeArea(const char* path){
   Image map = LoadImage(path);
    
   Color* pixels = GetImageData(map);
   float newX;
   float newY;

   SpriteGame *sprite;

   float width = map.width;
   float height = map.height;
   const char * sprite_tile_path = "./assets/spritesheet_Obj_stages.png"; 
   const char * sprite_tilehouse_path = "./assets/spritesheet_houses_ed_stages.png";

   for(int xx=0;xx<(int)width;xx++){
       for(int yy=0;yy<(int)height;yy++){
           Color pixel = pixels[xx+yy*((int)width)];
           newX = (float)xx * TILE_SIZE;
           newY = (float)yy * TILE_SIZE;

           switch(ColorToInt(pixel)){
              case 0x4CFF00FF: //Arvore
               sprite = new SpriteGame(sprite_tile_path,Rectangle{32*2,0,32,32});
               Obstacles.push_back(new Tree(newX,newY,*sprite));
               break;
           }
       }
   }
   
   mapwidth = width;
   mapheight = height;

}


void Game::GenerateWorld(const char* path, int type){
   switch(type){
      case CITY_TYPE:
        GenerateCity(path);
        break;
      case FREEAREA_TYPE:
        GenerateFreeArea(path);
        break;
      case BAR_TYPE:
        GenerateBar(path);
        break;
      case INN_TYPE:
        GenerateInn(path);
        break;
   }
}

void Game::CalculateCollisions(){
   for(int i=0;i<(int)Obstacles.size();i++){ 
      if((player->NotifyCollision(Obstacles[i]))){
         player->CollidedWall();
      }
   }
}

void Game::update(){
   CalculateCollisions(); /*Calcula as colisões entre os game objects*/
   
   player->update();

   for(int i=0;i<(int)Obstacles.size();i++){
      Obstacles[i]->update();
   }

   for(int i=0;i<(int)Objects.size();i++){
      Objects[i]->update();
   }

   for(int i=0;i<(int)Floor.size();i++){
      Floor[i]->update();
   }

   //for(int i=0;i<(int)tiles.size();i++){
     // tiles[i]->update();
      
      /*if((dynamic_cast<WallTile*>(tiles[i]))&&(player->isColliding(tiles[i]))){
         cout << "Player colidindo" << endl;
         player->setSpeed(0);
      }*/
   //}
    //camera.zoom+=0.001f; boa velocidade de zoom
    //mapa->update();
    
    //entities->update();
    Rectangle boxp;
    boxp = player->getBox();
    camera.target.x = Clamp(boxp.x - (screenWidth/2),0,(mapwidth*32) - screenWidth);
    camera.target.y = Clamp(boxp.y - (screenHeight/2),0,(mapheight*32) - screenHeight);
 }
    
 void Game::render(){
       
    BeginDrawing();
    BeginMode2D(camera);
        
    ClearBackground(BLACK);
    //DrawText("Tela do Jogo", 190, 200, 20, LIGHTGRAY);  
    //g.DrawSprite(Rectangle{16*2,0,16,16},50,70,16,16);

   //for(int i=0;i<(int)tiles.size();i++){
     // tiles[i]->render();
   //}
   for(int i=0;i<(int)Floor.size();i++){
      Floor[i]->render();
   }
   
   player->render(camera);

   for(int i=0;i<(int)Obstacles.size();i++){
      Obstacles[i]->render();
   }

   for(int i=0;i<(int)Objects.size();i++){
      Objects[i]->render();
   }
   
   DrawFPS(10+camera.target.x,10+camera.target.y);
    EndMode2D();
    EndDrawing();
        
 }
    
void Game::run(){
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Game Beta");
    //SetWindowIcon(); /*Mudar icone da janela*/
     //rend = LoadRenderTexture(640,480);
    //target = LoadRenderTexture(screenWidth, screenHeight);
    
    SpriteGame *sprite = new SpriteGame("./assets/spritesheet_MC.png",Rectangle{0,0,32,32});
    //entities.push_back(player);
    camera.offset = Vector2{0,0};
    camera.target = Vector2{0,0};
    camera.rotation = 0;
    camera.zoom = 1.0f;

    player = new Player(50,70,32,32,*sprite);
    player->SetMask(Rectangle{50,70,30,32});
    player->ScaleBox(2);
    GenerateWorld("./assets/fase_teste.png",CITY_TYPE);
    //Collider* col = new Collider(mapa->getMapPixels(),mapa->getWidth(),mapa->getHeight());
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
     {
        // Update
        update();
       //----------------------------------------------------------------------------------
       // TODO: Update your variables here
       //----------------------------------------------------------------------------------

       // Draw
       //----------------------------------------------------------------------------------
       render();
       //----------------------------------------------------------------------------------
     }

     //entities.clear();

     // De-Initialization
     //--------------------------------------------------------------------------------------
     CloseWindow();        // Close window and OpenGL context
     //--------------------------------------------------------------------------------------
 }