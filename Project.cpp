#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "objPosArrayList.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* game;// Gamemechs refrence 
Food* foodref; //Food refrence 
Player* player; // player refrence
objPos food2; //holds values of foodbucket if a collsion occured as well as the objPos value EQUAL which allows us to tell if a collsion occured around diffrent parts of the program


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void){
    Initialize(); 
    while(game->getExitFlagStatus() == false)//checks exit status  
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

    game = new GameMechs(26,13);//initialization with boarder values 26=x and 13=y
    player = new Player(game);//initialization
    foodref= new Food(game->getBoardSizeX(), game->getBoardSizeY());//initialization
    objPosArrayList *playerlist;//holds playerlist
    objPosArrayList* foodbucket;//holds foodbucket
    playerlist= player->getPlayerPos();
    foodref->generateFood(playerlist, game->getBoardSizeX(),game->getBoardSizeY()); 
    foodbucket=foodref->getFoodPos(); //initialization
    food2.EQUAL=0;//initialization
    
    


}

void GetInput(void){
   player->updatePlayerDir();//updating movement player directory
}

void RunLogic(void){
    if((food2.EQUAL)==1)
    {
        player->collision();
        objPosArrayList *playerlist;
        objPosArrayList* foodbucket;//holds foodbucket;
        playerlist= player->getPlayerPos();
        foodref->generateFood(playerlist, game->getBoardSizeX(), game->getBoardSizeY());
        foodbucket=foodref->getFoodPos();
        food2.EQUAL=0;
        if(food2.symbol== '@')//checking if food2 holds the special charecter, if so bonus points!!
        {
            game->incrementScore();//increment score by 10 points 
        }
        game->incrementScore();
    }
    player->movePlayer();//updates players x, y position
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    bool draw; 
    objPos temphead;
    objPos foodtemp;
    objPosArrayList* foodbucket;//holds foodbucket;
    foodbucket=foodref->getFoodPos();
    objPosArrayList *playerbody;
    playerbody=player->getPlayerPos();// holds the values of the players positions(i.e the 5 segments of itself or more)
    objPos tempbody;
    objPos playerPos;
    playerbody->getElement(temphead,0);// assigns the head of the snake to the objPos temphead
        for (int i = 0; i < game->getBoardSizeY(); i++){
            for (int j = 0; j < game->getBoardSizeX(); j++)
            {
                draw=false;
                if((temphead.x==j && temphead.y==i) && playerbody->getSize()==1)//basic body checking for printing the snake symbol if the body size only has the head element
                {
                    MacUILib_printf("%c", temphead.symbol);
                    for(int n=0; n<foodbucket->getSize(); n++ )
                    {
                        foodbucket->getElement(foodtemp,n);//gets the foodbucket items from the first one to the last one(the fifth one)
                        if(temphead.x==foodtemp.x && temphead.y==foodtemp.y)//checks to see if the head of the snake ahs the same position as a food item
                        {
                            food2=foodtemp;//assigns food2 to that food items for special charecter checking
                            food2.EQUAL=1;//sets food2 equal to 1 to ensure the proper collision protocal occurs
                        }
                    }   
                    j+=1;
                }

                for(int k=1; k< playerbody->getSize(); k++)
                {
                    playerbody->getElement(tempbody,k);//holds the body values of the snake
                    if((player->currentdir()!=true)&&(tempbody.x==temphead.x && tempbody.y==temphead.y))// checks to see if the player is in the STOP director, if not then collision with itself ends game
                    {
                        game->setExitTrue();
                    }
                    for(int n=0; n<foodbucket->getSize(); n++ )
                    {
                        foodbucket->getElement(foodtemp,n);//gets the foodbucket items from the first one to the last one(the fifth one)
                        if(temphead.x==foodtemp.x && temphead.y==foodtemp.y)//checks to see if the head of the snake ahs the same position as a food item
                        {
                            food2=foodtemp;//assigns food2 to that food items for special charecter checking
                            food2.EQUAL=1;//sets food2 equal to 1 to ensure the proper collision protocal occurs
                        }
                    }

                    if((tempbody.x==j && tempbody.y==i)||(temphead.x==j && temphead.y==i))//basic body checking for printing the snake symbol
                    {
                        MacUILib_printf("%c", temphead.symbol);
                        draw=true; //sets true after all body sysmbols and head symbol have been drawn
                        break;
                    }
                    
                }
                if(draw)
                {
                    draw=false;//reseting it to false for later use
                    continue;//allowing j value to increment to account for the printing of the snake body 
                }
                
                for(int n=0; n<foodbucket->getSize(); n++ )
                {
                    foodbucket->getElement(foodtemp, n);//holds foodbuckets items 
                    if(j==foodtemp.x && i==foodtemp.y)//printing condition
                    {
                        MacUILib_printf("%c", foodtemp.symbol); 
                        draw=true; 
                        break;
                    }
                    
                }
                if(draw)
                {
                    draw=false;//reseting it to false for later use
                    continue;//allowing j value to increment to account for the printing of the snake body 
                }
                
                if(j == game->getBoardSizeX()-1)//boarder checker 
                {
                    MacUILib_printf("#\n");
                }
                else if (i == 0 || j == 0 || i == game->getBoardSizeY()-1)//boarder checker
                {
                    MacUILib_printf("#");
                }      
    
                else
                {
                    MacUILib_printf(" ");
                }
               
            }
        }
        MacUILib_printf("SCORE:%d",game->getScore()); //score print at bottom of screen 
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();
    MacUILib_printf("GAME OVER\nFINAL SCORE: %d", game->getScore());   //end game message
    MacUILib_uninit();
}