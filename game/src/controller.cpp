#include "../lib/controller.hpp"

int Controller::getDir(){
    
    if( (IsKeyDown(KEY_W))
    || (IsKeyDown(KEY_UP)) ){
        return DIR_UP;
    }else if( (IsKeyDown(KEY_D))
    || (IsKeyDown(KEY_RIGHT)) ){
        return DIR_RIGHT;
    }else if( (IsKeyDown(KEY_A))
    || (IsKeyDown(KEY_LEFT)) ){
        return DIR_LEFT;
    }else if( (IsKeyDown(KEY_S))
    || (IsKeyDown(KEY_DOWN)) ){
        return DIR_DOWN;
    }

    if(IsGamepadAvailable(GAMEPAD_PLAYER1)){
      int player = GAMEPAD_PLAYER1;

      if(IsGamepadButtonDown(player,GAMEPAD_BUTTON_LEFT_FACE_UP)){
          return DIR_UP;
      }else if(IsGamepadButtonDown(player,GAMEPAD_BUTTON_LEFT_FACE_DOWN)){
          return DIR_DOWN;
      }else if(IsGamepadButtonDown(player,GAMEPAD_BUTTON_LEFT_FACE_LEFT)){
          return DIR_LEFT;
      }else if(IsGamepadButtonDown(player,GAMEPAD_BUTTON_LEFT_FACE_RIGHT)){
          return DIR_RIGHT;
      }
    }
    return -1;
}

int Controller::getAction(){
    
    if(IsKeyDown(KEY_Q)){
        return RUN;
    }else if(IsKeyReleased(KEY_Q)){
        return STOP_RUN;
    }

    if(IsGamepadAvailable(GAMEPAD_PLAYER1)){
        int player = GAMEPAD_PLAYER1;
        if(IsGamepadButtonDown(player,GAMEPAD_BUTTON_RIGHT_FACE_LEFT)){
            return RUN;
        }else if(IsGamepadButtonReleased(player,GAMEPAD_BUTTON_RIGHT_FACE_LEFT)){
            return STOP_RUN;
        }
    }
   
   return -1;
   
   
   /*
   switch(getDir()){
     case(DIR_RIGHT):
        break;
     case(DIR_LEFT):
        break;
     case(DIR_UP):
        break;
     case(DIR_DOWN):
        break;
   }*/
}