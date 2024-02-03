#include <vector>
#include <iostream>

#include "inventory.h"
#include "item.h"

inventory::inventory() {
    for(int i = 0; i < 8; i++){
        storedItems.emplace_back(i);
    }

}

void inventory::pickUpItem(item pItem) {
    item& yourItem = storedItems[pItem.getItemID()];
    if(yourItem == pItem){//kind of a redundant check but here for now
        int totalNum = yourItem.getNumItem() + pItem.getNumItem();
        if(totalNum > yourItem.getMaxNumItem()){
            yourItem.setNumItem(yourItem.getMaxNumItem());
            return;
        } else {
            yourItem.setNumItem(yourItem.getNumItem() + pItem.getNumItem());
            return;
        }
    }
    return;
}

bool inventory::dropItem(int pItemID, int pAmount) {
    item& yourItem = storedItems[pItemID];
    if(pAmount > yourItem.getNumItem()){
        return false;
    }else{
        yourItem.setNumItem(yourItem.getNumItem() - pAmount);
        return true;
    }
}
