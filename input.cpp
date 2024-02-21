#include <iostream>
#include <vector>

#include "inventory.h"
#include "player.h"
#include "item.h"
#include "input.h"

using namespace std;


char input::actionMenu(vector<std::string> options,player& p,
                       inventory& i,bool showMap,bool showInventory,
                       bool isSubArea) {
    vector<char> acceptedChoices;
    string choice;
    cout << bar;

    for(int i = 0; i < options.size(); i++){
        cout << optionsKey[i] << options[i] << endl;
        acceptedChoices.push_back(optionsKey[i][0]);
    }

    if(isSubArea){
        cout << "l)leave" << endl;
        acceptedChoices.push_back('l');
    }

    if(showInventory){
        cout << "i)inventory" << endl;
    }

    if(showMap){
        if(p.getDiscoveredLocations().size() > 1) {
            cout << "m)map" << endl;
            acceptedChoices.push_back('m');
        }
    }

    cout << "input the letter of your action:";
    while(getline(cin, choice)){
        if(choice.size() > 1){
            cout << "please only enter one letter" << endl;
        } else if(choice.size() == 0){
            cout << "NO INPUT - please enter a letter" << endl;
        } else {
            for(char c:acceptedChoices){
                if(c == choice[0]){
                    return choice[0];
                }
            }
            if(choice[0] == 'i' && showInventory){
                cout << i <<endl;
                cout << bar;
                return 'i';
            }
            cout << "not an accepted answer" << endl;
        }
        cout << "enter a new answer:";
    }
    return '0';
}

char input::mapMenu(player& p) {
    vector<char>acceptedChoices;
    string choice;
    cout << bar;
    for(locations l:p.getDiscoveredLocations()){
        cout << optionsKey[(int)l] << locationNames[(int)l] << endl;
        acceptedChoices.push_back(optionsKey[(int)l][0]);
    }
    cout << "input the letter of your action:";
    while(getline(cin,choice)){
        if(choice.size() < 1){
            cout << "please only enter one letter" <<endl;
        } else if (choice.empty()){
            cout << "Invalid - please enter a choice" << endl;
        } else {
            for(char c:acceptedChoices){
                if(choice[0] == c){
                    return choice[0];
                }
            }
            cout << "not an option" << endl;
        }
        cout << "Enter a new answer:";

    }
    return '0';
}