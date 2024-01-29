#include <random>
#include <iostream>

#include "field.h"

using namespace std;

void field::milkCows() {
    if(cowsMilked){
        cout << "You have already milked the cows they don't have any more to give" << endl;
    } else {
        cowsMilked = true;
    }
}

void field::searchCarriage() {

}

void field::visitFortress() {

}
