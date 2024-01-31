#include <iostream>
#include "item.h"


item::item(itemType pThisItem, int pNumItem) {
    thisItem = pThisItem;
    numItem = pNumItem;
    if(thisItem == lantern||thisItem == cloak||thisItem == pocketBlackHole){
        maxNumItem = 1;
    } else if(thisItem == bomb||thisItem == milkBucket||thisItem == knife){
        maxNumItem = 3;
    } else if(thisItem == potion){
        maxNumItem = 5;
    } else if(thisItem == bandage){
        maxNumItem = 10;
    } else {
        maxNumItem = 999;
    }
    if(numItem > maxNumItem){
        numItem = maxNumItem;
    }
}

//delegating constructors
item::item(int pItemId) : item(itemType(pItemId),0){}

string item::getItem() {
    return itemTypeNames[thisItem];//itemTypeNames is a vector
}

int item::getItemID() {
    return int(thisItem);
}

int item::getNumItem() {
    return numItem;
}

int item::getMaxNumItem() {
    return maxNumItem;
}

void item::setNumItem(int pNumItem) {
    numItem = pNumItem;
}


