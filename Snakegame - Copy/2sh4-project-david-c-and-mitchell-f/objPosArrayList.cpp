#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
objPosArrayList::objPosArrayList()
{
    aList= new objPos[ARRAY_MAX_CAP]; 
    sizeList=0;//no valid elements in the list upon start up
    sizeArray=ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if( sizeList==sizeArray)
    {

    }
    else
    {
        for(int i= sizeList; i>0; i--)
        {
            aList[i].setObjPos(aList[i-1]); // this will shuffle all the elements towardss the tail
        }
        aList[0].setObjPos(thisPos); 
        sizeList++;
    } 
   
}

void objPosArrayList::insertTail(objPos thisPos)
{
    int temp= sizeList; 
    if(sizeList==sizeArray)
    {

    }
    else
    {
        for(int i=0; i<(temp-1); i++)
        {
            aList[i].setObjPos(aList[i+1]); // this will shuffle all the elements towardss the tail
        }
        aList[temp].setObjPos(thisPos);  
        sizeList++;

    }
}

void objPosArrayList::removeHead()
{
    aList[0]=aList[sizeList-1]; 
    sizeList--;   
}

void objPosArrayList::removeTail()
{
    sizeList--;   
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]); 
}