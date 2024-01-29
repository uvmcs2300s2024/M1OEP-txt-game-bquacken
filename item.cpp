#include "item.h"

item::item(item::itemType pThisItem, int pNumItem) {
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
}

string item::getItem() {
    return itemTypeNames[thisItem];//itemTypeNames is a vector
}

item::itemType item::getItemID() {
    return thisItem;
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

ostream& operator<<(ostream& out, item& i){
    out << i.getItem() << "(" << i.getNumItem() << ")" << endl;

    return out;
}

bool operator==(item& lhs, item& rhs){
    return lhs.getItem() == rhs.getItem();
}

bool operator<(item& lhs, item& rhs){
    return lhs.getNumItem() < rhs.getNumItem();
}

bool operator>(item& lhs, item& rhs){
    return lhs.getNumItem() > rhs.getNumItem();
}
