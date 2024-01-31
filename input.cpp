#include <iostream>
#include <vector>

#include "inventory.h"
#include "player.h"
#include "item.h"
#include "input.h"

using namespace std;


char input::actionMenu(vector<std::string> options) {
    vector<char> acceptedChoices;
    string choice;
    for(int i = 0; i < options.size(); i++){
        cout << optionsKey[i] << options[i] << endl;
        acceptedChoices.push_back(optionsKey[i][0]);
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
            cout << "not an accepted answer" << endl;
        }
        cout << "enter a new answer:";
    }
}