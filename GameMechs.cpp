#include "GameMechs.h"
#include "MacUILib.h"

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
}

// do you need a destructor?
GameMechs::~GameMechs(){

}

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