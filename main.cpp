#include <ostream>
#include <iostream>

#include "inventory.cpp"
#include "item.cpp"
#include "input.cpp"
#include "player.cpp"
#include "field.cpp"


using namespace std;

int main(){

    player you = player();
    you.getDiscoveredLocations().push_back(grassLands);
    bool playing = true;
    field fieldArea;

    while(playing){
        switch (you.getPLayerLocation()) {
            case(grassLands):
                fieldArea.init();
                switch (input().actionMenu(fieldOptions,you,sack,
                                           true, true, false)) {
                    case('a'):
                        fieldArea.milkCows(you.getStuff());
                        break;
                    case('b'):
                        fieldArea.searchCarriage(you.getStuff());
                        break;
                    case('c'):
                        fieldArea.visitFortress(you);
                        break;
                    case('i'):
                        break;
                    case('m'):
                        char travel = input().mapMenu(you);
                        switch(travel){
                            case('a'):
                                cout << "You're already here" << endl;
                                break;
                            case('b'):
                                cout << "are you sure?" << endl;
                                char check = input().actionMenu({"Leave","Stay"},you,
                                                                you.getStuff(),false,
                                                                false, false);
                                switch(check){
                                    case('a'):
                                        you.setPlayerLocation(darkCaves);
                                        break;
                                    case('b'):
                                        break;
                                }
                                break;
                        }
                        break;
                }
                break;
            case(darkCaves):
                cout << "bye" << endl;
                playing = false;
                break;
        }
    }




    return 0;
}