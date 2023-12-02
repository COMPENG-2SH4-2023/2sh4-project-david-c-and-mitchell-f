#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* game;
Player* player; 
objPos food1;


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
    game->getFoodPos(food1);
    food1.EQUAL=0;
    
    


}

void GetInput(void){
   player->updatePlayerDir();
}

void RunLogic(void){
    MacUILib_printf("%d", food1.EQUAL);
    if((food1.EQUAL)==1)
    {
        player->collision();
        game->getFoodPos(food1);
        food1.EQUAL=0;
    }
    player->movePlayer();
}

void DrawScreen(void){
    MacUILib_clearScreen();
    int p;
    bool draw;
    objPosArrayList *playerbody;
    playerbody=player->getPlayerPos();
    objPos tempbody;
    objPos playerPos;

   
    
        for (int i = 0; i < game->getBoardSizeY(); i++){
            for (int j = 0; j < game->getBoardSizeX(); j++)
            {
                draw=false;

                for(int k=0; k< playerbody->getSize(); k++ )
                {
                    playerbody->getElement(tempbody,k);
                    if(tempbody.x==food1.x && tempbody.y==food1.y)
                    {
                        food1.EQUAL=1;
                    }
                    if(tempbody.x==j && tempbody.y==i )
                    {
                        MacUILib_printf("%c", tempbody.symbol);
                        draw=true; 
                        break;
                    }
                    
                }
                if(draw)
                {
                    continue;
                }
                
                if(j==food1.x && i==food1.y)
                {
                    MacUILib_printf("%c", food1.symbol);
                    continue;
                }
                
                if(j == game->getBoardSizeX()-1){
                    MacUILib_printf("#\n");
                }
                else if (i == 0 || j == 0 || i == game->getBoardSizeY()-1){
                    MacUILib_printf("#");
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

void LoopDelay(void)
{
    
    MacUILib_Delay(200000); // 0.1s delay
}

void CleanUp(void){
    MacUILib_clearScreen();    
    MacUILib_uninit();
}