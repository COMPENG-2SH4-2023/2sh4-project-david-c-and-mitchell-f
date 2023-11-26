#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000
#define HORIZONTAL 20
#define VERTICAL 10 

bool exitFlag;

objPos playerPos;
objPos apple;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    playerPos.setObjPos(9,5,'@');
    apple.setObjPos(1,1,'$');

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    if(exitFlag == 0){
        for (int i = 0; i < VERTICAL; i++){
            for (int j = 0; j < HORIZONTAL; j++){
                if(j == 19){
                    MacUILib_printf("#\n");
                }
                else if (i == 0 || j == 0 || i == 9){
                    MacUILib_printf("#");
                }      
                else if(i == playerPos.y && j == playerPos.x){
                    MacUILib_printf("%c", playerPos.symbol);
                }
                else if(i == apple.y && j == apple.x){
                    MacUILib_printf("%c", apple.symbol);
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
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
