#include "GameMechs.h"
#include "MacUILib.h"
#include <stdlib.h>
#include <time.h>
#include "objPosArrayList.h"

GameMechs::GameMechs(){
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 20;
    boardSizeY = 10;
    score = 0;
    //initiallizing basic values
}

GameMechs::GameMechs(int boardX, int boardY){
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
    srand(time(NULL));// placed here to ensure the randomness of the function
   
}
// do you need a destructor?
//no since the gameMechs built in food gen function was replaced by the Food classes one, also new was never called
/*
GameMechs::~GameMechs(){
    delete food;
}
*/
bool GameMechs::getExitFlagStatus(){
    return exitFlag;
}

void GameMechs::setExitTrue(){
    exitFlag = true;
}

bool GameMechs::getLoseFlagStatus(){
    return loseFlag;
}

void GameMechs::setLoseFlag(){
    loseFlag = true;
}

char GameMechs::getInput(){
    if (MacUILib_hasChar()){
        input = MacUILib_getChar();//input collection
    }
    return input;
}

void GameMechs::setInput(char thisInput){
    input = thisInput;
}

void GameMechs::clearInput(){
    input = 0;
}

int GameMechs::getBoardSizeX(){
    return boardSizeX;
}

int GameMechs::getBoardSizeY(){
    return boardSizeY;
}

int GameMechs::getScore(){
    return score;
}

void GameMechs::incrementScore(){
    score += 10;
}

void GameMechs::generateFood(objPosArrayList* blockOff){
    srand(time(NULL));
    objPos posholder; //hold player positions
    int k;
    k=blockOff->getSize();//holds size of player body
    int i;
    food.setObjPos(1+(rand() % (boardSizeX-1)), 1+(rand() % (boardSizeY-1)),'o');
    for(i=0; i<k; i++)
    {
        blockOff->getElement(posholder,i);// holds player position starting from the head element to all the body elements

        if(posholder.x==food.x && posholder.y==food.y)//ensuring the food element cannot generate on the bpody element 
        {
            food.setObjPos(1+(rand() % (boardSizeX-1)), 1+(rand() % (boardSizeY-1)),'o');// random function
        }
    }
}

void GameMechs::getFoodPos(objPos &returnPos){
    srand(time(NULL));
    returnPos.setObjPos(food);
    
}
