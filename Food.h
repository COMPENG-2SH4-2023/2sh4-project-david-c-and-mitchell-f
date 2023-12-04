#ifndef FOOD_H
#define FOOD_H
#include <cstdlib>
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        objPos norm; 
        objPos Special;
        void generateFood(objPosArrayList* blockOff, int x, int y);
        Food(int x, int y);
        objPosArrayList* getFoodPos();
        ~Food(); 
        objPosArrayList* foodBucket;
    private: 
        GameMechs* gameref;
        
};

#endif