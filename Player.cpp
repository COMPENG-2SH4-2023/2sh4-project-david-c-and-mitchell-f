#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

	// Insert 4 body elements, then 1 unique head element
	
   // more actions to be included
    objPos temp;
    temp.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*'); 
    playerPosList= new objPosArrayList();
    playerPosList->insertHead(temp); 
    playerPosList->insertHead(temp); 
    playerPosList->insertHead(temp); 
    playerPosList->insertHead(temp); 
    playerPosList->insertHead(temp); 
      
}


Player::~Player()
{
    // delete any heap members here
    delete[] playerPosList; 
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList; 
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput(); 
    switch(input)
    {
        case 27:
            myDir=EXIT;
            break;
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
    objPos currhead;
    playerPosList->getHeadElement(currhead);
    switch(myDir)
        {
            case EXIT:
                mainGameMechsRef->setExitTrue(); 
            case UP:
                currhead.y--;
                if(currhead.y<=0)
                {
                    currhead.y=mainGameMechsRef->getBoardSizeY()-2; 
                    
                } 
                break;


            case LEFT:
                currhead.x-=1;
                
                if(currhead.x<=0)
                {
                    currhead.x=mainGameMechsRef->getBoardSizeX()-2; 
                
                }
                break;


            case RIGHT:
                currhead.x+=1;
            
                if(currhead.x==(mainGameMechsRef->getBoardSizeX()-1))
                {
                    currhead.x=1; 
                    
                }
                break;


            case DOWN:
                currhead.y+=1;
                if(currhead.y==(mainGameMechsRef->getBoardSizeY()-1))
                {
                    currhead.y=1; 
                    
                }
                break;

            case STOP:
                break;

            default:
                MacUILib_printf("unknown node"); 
                break;
        }
        playerPosList->insertHead(currhead);
        playerPosList->removeTail(); 
        // PPA3 Finite State Machine logic
    }

