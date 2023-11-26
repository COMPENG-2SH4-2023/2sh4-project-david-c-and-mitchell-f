#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* game;
Player* player;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void){
    Initialize();
    while(game->getExitFlagStatus() == false)  
    {
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
}

void GetInput(void){
   player->updatePlayerDir();
}

void RunLogic(void){
    player->movePlayer();
}

void DrawScreen(void){
    MacUILib_clearScreen();
    objPos playerPos;
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
                    /*
                    hasChar = 0;
                    for(k = 0; k < 5; k++){
                        if((i == itemBin[k].y) && (j == itemBin[k].x)){
                            MacUILib_printf("%c", itemBin[k].symbol);
                            hasChar = 1;
                        }
                    }*/
                    //if (hasChar == 0) 
                    MacUILib_printf(" ");
                    
                }
            }
        // [TODO]   Display the "Mystery String" contents at the bottom of the game board
        //          To help players keep track of their game progress.
        }
        //for (i = 0; i < my_strlen(goalString); i++) MacUILib_printf("%c", mysteryString[i]);
        //MacUILib_printf("\nMove Count: %d", moveCount);
        //MacUILib_printf("\nPress space to exit at anytime\n");
}

void LoopDelay(void){
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void){
    MacUILib_clearScreen();    
    MacUILib_uninit();
}