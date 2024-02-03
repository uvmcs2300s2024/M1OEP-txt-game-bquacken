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
    inventory sack = inventory();
    you.getDiscoveredLocations().push_back(grassLands);
    bool playing = true;
    field fieldArea;

    while(playing){
        switch (you.getPLayerLocation()) {
            case(grassLands):
                fieldArea.init();
                switch (input().actionMenu(fieldOptions,you,sack,
                                           true, true)) {
                    case('a'):
                        fieldArea.milkCows(sack);
                        break;
                    case('b'):
                        fieldArea.searchCarriage(sack);
                        break;
                    case('c'):
                        fieldArea.visitFortress(sack,you);
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
                                                                sack,false,
                                                                false);
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