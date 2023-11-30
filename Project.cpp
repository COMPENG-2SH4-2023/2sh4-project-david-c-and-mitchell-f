#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* game;
Player* player;
objPos food;
objPos playerPos;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void){
    Initialize();
    while(game->getExitFlagStatus() == false){
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }
    CleanUp();
}

void Initialize(void){
    MacUILib_init();
    MacUILib_clearScreen();

    game = new GameMechs(26,13);
    player = new Player(game);
    game->generateFood(playerPos);
    game->getFoodPos(food);
}

void GetInput(void){
   player->updatePlayerDir();
}

void RunLogic(void){
    player->movePlayer();
    game->clearInput();
}

void DrawScreen(void){
    MacUILib_clearScreen();
    
    player->getPlayerPos(playerPos);
    for (int i = 0; i < game->getBoardSizeY(); i++){
        for (int j = 0; j < game->getBoardSizeX(); j++){
            if(j == game->getBoardSizeX()-1){
                MacUILib_printf("#\n");
            }
            else if (i == 0 || j == 0 || i == game->getBoardSizeY()-1){
                MacUILib_printf("#");
            }      
            else if(i == playerPos.y && j == playerPos.x){
                MacUILib_printf("%c", playerPos.symbol);
            }
            else{
                int spaceCondition = 0;
                if((i == food.y) && (j == food.x)){
                    MacUILib_printf("%c", food.symbol);
                    spaceCondition = 1;
                } 
                if (spaceCondition == 0){
                    MacUILib_printf(" ");   
                } 
            }
        }
    }
}

void LoopDelay(void){
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void){
    MacUILib_clearScreen();    
    MacUILib_uninit();
}