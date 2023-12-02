#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList= new objPos[ARRAY_MAX_CAP]; 
    listsize=0;//no valid elements in the list upon start up
    arraycapacity=ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return listsize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listsize==arraycapacity)
    {

    }
    else
    {
        for(int i=listsize; i>0; i--)
        {
            aList[i].setObjPos(aList[i-1]); // this will shuffle all the elements towardss the tail
        
        }
        aList[0].setObjPos(thisPos); 
        listsize++;
    }
   
}

void objPosArrayList::insertTail(objPos thisPos)
{
    int temp=listsize; 
    if(listsize==arraycapacity)
    {

    }
    else
    {
        for(int i=0; i<(temp-1); i++)
        {
            aList[i].setObjPos(aList[i+1]); // this will shuffle all the elements towardss the tail
        
        }
        aList[temp].setObjPos(thisPos);  
        listsize++;

    }
}

void objPosArrayList::removeHead()
{
    aList[0]=aList[listsize-1]; 
    listsize--;   
}

void objPosArrayList::removeTail()
{
    listsize--;   
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listsize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]); 
}