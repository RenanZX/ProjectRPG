#include "../lib/player.hpp"

    Player::Player(float x, float y, float width, float height, SpriteGame sprite) : GameObj(x,y,width,height) {
        this->sprite = sprite;
        float size = TILE_SIZE;
        this->downplayer = Rectangle{0,0,size,size}; //tamanho do sprite tale_size
        this->upplayer = Rectangle{0,size,size,size};
        this->leftplayer = Rectangle{0,size*3,size,size};
        this->rightplayer = Rectangle{0,size*2,size,size};
    }

    int Player::AreaLocked(Vector2 x){
      Rectangle checkbox = Rectangle{x.x,x.y,mask.width,mask.height};
      if(CheckCollisionRecs(checkbox,colisionBox)){
        Rectangle box2 = GetCollisionRec(checkbox,colisionBox);
        return box2.width*box2.height;
      }
      return -1;
    }

    void Player::FreeMove(Vector2 p1,Vector2 p2, Vector2 p3, Vector2 p4){
      /*if(CheckCollisionPointRec(p1,colisionBox)){
        up_dir = false;
      }

      if(CheckCollisionPointRec(p2,colisionBox)){
        down_dir = false;
      }

      if(CheckCollisionPointRec(p3,colisionBox)){
        right_dir = false;
      }

      if(CheckCollisionPointRec(p4,colisionBox)){
        left_dir = false;
      }*/
      
      priority_queue<int> areas;
      areas.push(AreaLocked(p1));
      areas.push(AreaLocked(p2));
      areas.push(AreaLocked(p3));
      areas.push(AreaLocked(p4));
      int maior = areas.top();

      if(AreaLocked(p1) >= maior){
        up_dir = false;
      }
      if(AreaLocked(p2) >= maior){
        down_dir = false;
      }
      if(AreaLocked(p3) >= maior){
        right_dir = false;
      }
      if(AreaLocked(p4) >= maior){
        left_dir = false;
      }
    }

    void Player::CollidedWall(){
      FreeMove(Vector2{mask.x,mask.y-speed},
      Vector2{mask.x,mask.y+speed},
      Vector2{mask.x+speed,mask.y},
      Vector2{mask.x-speed,mask.y});
    }

    void Player::ResetDirs(){
      right_dir = true;
      left_dir = true;
      up_dir = true;
      down_dir = true;
    }

    void Player::update(){
       frametime+= GetFrameTime();
       if(frametime >= 0.15f){
          frametime = 0;
          ind++;
       }
       ind = ind % maxInd;

       if((controller.getDir() == DIR_UP)&&(up_dir)){
         box.y-=speed;
         sprite.setRectSprite(upplayer);
       }else if((controller.getDir() == DIR_DOWN)&&(down_dir)){
         box.y+=speed;
         sprite.setRectSprite(downplayer);
       }else if((controller.getDir() == DIR_LEFT)&&(left_dir)){
         box.x-=speed;
         sprite.setRectSprite(leftplayer);
       }else if((controller.getDir() == DIR_RIGHT)&&(right_dir))
       {
         box.x+=speed;
         sprite.setRectSprite(rightplayer);
       }else{
         ind = 0;
       }

       ResetDirs();

       switch(controller.getAction()){
           case RUN:
             speed = runningspeed;
             downplayer.y = 32 * 4;
             upplayer.y = 32 * 5;
             rightplayer.y = 32 * 6;
             leftplayer.y = 32 * 7;
             break;
           case STOP_RUN:
             speed = normalspeed;
             downplayer.y = 0;
             upplayer.y = 32;
             rightplayer.y = 32 * 2;
             leftplayer.y = 32 * 3;
       }

      UpdateMask();
    
    }
    
    void Player::render(Camera2D cam){
       //movimentando
       
       Rectangle rect = sprite.getRectSprite();
       rect.x = TILE_SIZE*ind;
       sprite.setRectSprite(rect);
       
       box.x = box.x - cam.offset.x;
       box.y = box.y - cam.offset.y;
       sprite.DrawSprite(box);
       //DrawRectangleRec(mask,BLUE);
    }