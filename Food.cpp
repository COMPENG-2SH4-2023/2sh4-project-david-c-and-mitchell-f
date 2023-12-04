#include "Food.h"
#include "MacUILib.h"
#include <stdlib.h>
#include <time.h>


Food::Food(int x, int y)
{
    srand(time(NULL));//put here to random time
    int i; 
    
    foodBucket= new objPosArrayList();//makeing space on heap for foodbucket
    for(i=0; i<3; i++)
    {
        norm.setObjPos(1+(rand() % (x-2)), 1+(rand() % (y-2)),'O');//put in for loop to randomize the results, setting objPos norm to hod the data values for normal food
        foodBucket->insertHead(norm);//inserting into foodbucket 
    }
    for(i=0; i<2; i++)
    {
        Special.setObjPos(1+(rand() % (x-2)), 1+(rand() % (y-2)),'@');// objPos special hold the values for special food
        foodBucket->insertHead(Special);//inserting into food bucket
    }
 

}

Food::~Food()
{
    delete[] foodBucket;// clearing memory of food bucket on heap
}

void Food::generateFood(objPosArrayList* blockOff, int x, int y){
    srand(time(NULL));
    int i;
    int j;
    int n;
    int p;
    objPos posholder;
    objPos temp; 
    
    for(i=0; i< blockOff->getSize(); i++)
    {
        blockOff->getElement(posholder,i);

        for (j=0; j<foodBucket->getSize(); j++)
        {
            foodBucket->getElement(temp, j); //holds each food bucket element as it progresses through loop
            while(posholder.x==temp.x && posholder.y==temp.y)//checks to ensure they dont equal the player position
            {  
                for(p=0; p<5; p++)//removing all the eleemnts if a food element equals the player position
                {
                    foodBucket->removeHead();
                }
                for(p=0; p<3; p++)//creating new normal food elements 
                {
                    norm.setObjPos(1+(rand() % (x-2)), 1+(rand() % (y-2)),'O'); 
                    foodBucket->insertHead(norm);
                }
                for(n=0; n<2; n++)//creating new special food elements
                {
                    Special.setObjPos(1+(rand() % (x-2)), 1+(rand() % (y-2)),'@');
                    foodBucket->insertHead(Special);
                }
                foodBucket->getElement(temp, j);
            }
        }
    }
}

objPosArrayList* Food::getFoodPos()
{
    return foodBucket;// returns food bucket
}