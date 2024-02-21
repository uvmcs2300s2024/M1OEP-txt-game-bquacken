#include "SubAreaTemplate.h"

SubAreaTemplate::SubAreaTemplate(vector<vector<item>> items, std::string areaTxt, vector<std::string> options,
                                 vector<string> optionsTxt,bool hasEncounter) {
    this -> items = items;
    this -> areaTxt = areaTxt;
    this -> options = options;
    this -> optionsTxt = optionsTxt;
    this -> hasEncounter = hasEncounter;
    for(int i = 0;  i < options.size(); i++){
        isSearched.push_back(false);
    }
}

void SubAreaTemplate::visit(player& p) {
    cout << areaTxt << endl;
    bool active = true;

    while(active){
        char choice = input().actionMenu(options,p,p.getStuff(),false,true, true);
        for(int i = 0; i < options.size(); i++){
            if(optionsKey[i] == choice){
                search(p,i * 2);
            }
        }
    }

}

void SubAreaTemplate::search(player& p, int lowerIndex) {
    if(isSearched[lowerIndex]){
        cout << optionsTxt[lowerIndex + 1] << endl;
    }else{
        cout << optionsTxt[lowerIndex] << endl;
        if(!items[lowerIndex].empty()){
            cout << "You found: " << endl;
            for(item x:items[lowerIndex]){
                p.getStuff().pickUpItem(x);
                cout << x << endl;
            }
        }
    }
}