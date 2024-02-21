#include "SubAreaTemplate.h"

SubAreaTemplate::SubAreaTemplate(vector<vector<item>> items, std::string areaTxt, vector<std::string> options,
                                 vector<string> optionsTxt, bool hasEncounter) {
    this -> items = items;
    this -> areaTxt = areaTxt;
    this -> options = options;
    this -> optionsTxt = optionsTxt;
    this -> hasEncounter = hasEncounter;
    for(int i = 0;  i < options.size(); i++){
        isSearched.push_back(false);
    }
}

void SubAreaTemplate::visit() {
    cout << areaTxt << endl;
    switch (input().actionMenu(options,p,i,false,true, true)) {
        case('a'):

    }

}

void SubAreaTemplate::search(int lowerIndex) {
    if(isSearched[lowerIndex]){
        cout << optionsTxt[lowerIndex + 1] << endl;
    }else{
        cout << optionsTxt[lowerIndex] << endl;
        if(!items[0].empty()){
            cout << "You found: " << endl;
            for(item x:items[lowerIndex]){
                i.pickUpItem(x);
                cout << x << endl;
            }
        }
    }
}