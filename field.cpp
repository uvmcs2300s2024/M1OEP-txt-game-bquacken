#include "field.h"

using namespace std;


void field::init() {
    cout << "you're standing in a field of waist high grass. you see a ruined" <<
            " carriage that is laying on its side, \nthere are some cows a short walk away" <<
            " and in the distance you see a fortress although it looks abandoned." << endl;
}


void field::milkCows(inventory& i) {
    if(cowsMilked){
        cout << "You have already milked the cows they don't have any more to give" << endl;
    } else {
        cowsMilked = true;
        cout << "you milked the cows you got: Milk Bucket(1)" << endl;
        i.pickUpItem(item(milkBucket,1));
    }
}

void field::searchCarriage(inventory& i) {
    if(carriageSearched){
        cout << "There is nothing left here" << endl;
    }else {
        carriageSearched = true;
        srand(time(NULL));
        int coinAmount = rand() % 25 + 1;
        cout << "you found:\ncoins(" << coinAmount << ")\nknife(1)" << endl;
        i.pickUpItem(item(coin,coinAmount));
        i.pickUpItem(item(knife,1));
    }
}

void field::visitFortress(player& p) {
    vector<string> fortressOptions = {"search tents","climb the tower"};
    if(fortressVisited && encampmentVisited && towerVisited){
        cout << "There is nothing left here" << endl;
    } else {
        cout << "you enter the small fortress in the field it seems abandoned\n" <<
                "There is an area with tattered tents sprawled out and a rickety watchtower.\n" <<
                "maybe they left something behind?" <<endl;
        fortressVisited = true;
        char playerChoice = input().actionMenu(fortressOptions,p,false, true,true);
        while(playerChoice != 'l'){
            if(playerChoice == 'a'){
                if(encampmentVisited){
                    cout << "there is nothing left but ruined clothes and tents" << endl;
                }else{
                    encampmentVisited = true;
                    cout << "you walk through rows of collapsing tents with muddy clothes strewn about" << endl;
                    srand(time(NULL));
                    int coinAmount = rand() % 50 + 1;
                    cout << "you find a small purse containing:\ncoins(" << coinAmount << ")" << endl;
                    cout << "At the end of the row of tents you find some fresh bandages:\nbandages(2)" << endl;
                    p.getStuff().pickUpItem(item(coin,coinAmount));
                    p.getStuff().pickUpItem(item(bandage,2));
                }
            } else if (playerChoice == 'b') {
                if (towerVisited) {
                    cout << "theres nothing left but a pile of wooden beams?" << endl;
                } else {
                    cout << "you approach the tower cautiously.\nas you set you put your weight on" <<
                         " the lowest rung of the ladder it creaks in protest.\nHow old is this place?"
                         << endl;

                    cout << "With each step higher you feel the swaying of the tower in the wind.\n" <<
                         "At the top there is a small box that contains a potion and a worn map" << endl;
                    p.getStuff().pickUpItem(item(potion, 1));
                    p.getDiscoveredLocations().push_back(darkCaves);

                    cout << "you climb back down the tower shaking with each step\n" <<
                         "When you reach the bottom you walk away glad the tower didn't collapse"
                         << endl;
                    towerVisited = true;
                }
            }
            playerChoice = input().actionMenu(fortressOptions,p,false, true, true);
        }
    }
}
