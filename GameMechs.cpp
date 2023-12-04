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
}

GameMechs::GameMechs(int boardX, int boardY){
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
    srand(time(NULL));
   
}
// do you need a destructor?
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
        input = MacUILib_getChar();
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
    objPos posholder; 
    int k;
    k=blockOff->getSize(); 
    int i;
    food.setObjPos(1+(rand() % (boardSizeX-2)), 1+(rand() % (boardSizeY-2)),'o');
    for(i=0; i<k; i++)
    {
        blockOff->getElement(posholder,i);

        if(posholder.x==food.x && posholder.y==food.y)
        {
            food.setObjPos(1+(rand() % (boardSizeX-2)), 1+(rand() % (boardSizeY-2)),'o');
        }
    }
}

void GameMechs::getFoodPos(objPos &returnPos){
    srand(time(NULL));
    returnPos.setObjPos(food);
    
}
