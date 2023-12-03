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
    objPosArrayList *playerlist;
    playerlist= player->getPlayerPos();
    game->generateFood(playerlist);
    game->getFoodPos(food1); 
    food1.EQUAL=0;
    
    


}

void GetInput(void){
   player->updatePlayerDir();
}

void RunLogic(void){
    if((food1.EQUAL)==1)
    {
        player->collision();
        objPosArrayList *playerlist;
        playerlist= player->getPlayerPos();
        game->generateFood(playerlist);
        game->getFoodPos(food1);   
        food1.EQUAL=0;
        game->incrementScore();
    }
    player->movePlayer();
}

void DrawScreen(void){
    MacUILib_clearScreen();
    int p;
    bool draw;
    objPos temphead;
    objPosArrayList *playerbody;
    playerbody=player->getPlayerPos();
    objPos tempbody;
    objPos playerPos;
    int score;
    playerbody->getElement(temphead,0);
        for (int i = 0; i < game->getBoardSizeY(); i++){
            for (int j = 0; j < game->getBoardSizeX(); j++)
            {
                draw=false;

                for(int k=1; k< playerbody->getSize(); k++ )
                {
                    playerbody->getElement(tempbody,k);
                    if((player->currentdir()!=true)&&(tempbody.x==temphead.x && tempbody.y==temphead.y))
                    {
                        game->setExitTrue();
                    }
                    if(temphead.x==food1.x && temphead.y==food1.y)
                    {
                        food1.EQUAL=1;
                    }
                    if((tempbody.x==j && tempbody.y==i) || (temphead.x==j && temphead.y==i))
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
                
                
                
                else
                {
                    MacUILib_printf(" ");
                }
               
            }
        }
        score=game->getScore();
        MacUILib_printf("SCORE:%d",score); 
    
}

void LoopDelay(void)
{
    
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void){
    MacUILib_clearScreen();    
    MacUILib_uninit();
}