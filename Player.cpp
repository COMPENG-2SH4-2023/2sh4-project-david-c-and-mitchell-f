#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.setObjPos(5,5,'@');

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol); 
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); 
    switch(input)
    {
        case 'w': 
                if(myDir!=DOWN)
                {
                    myDir=UP;
                }
                break;
            case 'a': 
                if(myDir!=RIGHT)
                {
                    myDir=LEFT;
                }
                break;     
            case 's': 
                if(myDir!=UP)
                {
                    myDir=DOWN;
                }
                break; 
            case 'd': 
                if (myDir!=LEFT)
                {
                    myDir=RIGHT;
                }
                break;  

            default:
                break;
    }
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
   switch(myDir)
    {
        case DOWN:
            playerPos.y-=1;
            if(playerPos.y==0)
            {
                playerPos.y=8; 
            }
            break;


        case LEFT:
            playerPos.x-=1;
            if(playerPos.x==0)
            {
                playerPos.x=18; 
            }
            break;


        case RIGHT:
            playerPos.x+=1; 
            if(playerPos.x==19)
            {
                playerPos.x=1; 
            }
            break;


        case UP:
            playerPos.y+=1;
            if(playerPos.y==9)
            {
                playerPos.y=1; 
            }
            break;

        case STOP:
            break;

        default:
            MacUILib_printf("unknown node"); 
            break;
    }
    // PPA3 Finite State Machine logic
}

