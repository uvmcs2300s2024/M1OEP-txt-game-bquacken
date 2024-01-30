#include <random>
#include <iostream>
#include <vector>

#include "field.h"
#include "inventory.h"
#include "item.h"

using namespace std;

void field::milkCows(inventory& i) {
    if(cowsMilked){
        cout << "You have already milked the cows they don't have any more to give" << endl;
    } else {
        cowsMilked = true;
        i.pickUpItem(item(milkBucket,1));
    }
}

void field::searchCarriage() {

}

void field::visitFortress() {

}
