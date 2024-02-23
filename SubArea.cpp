#include "SubArea.h"

SubArea::SubArea(std::string areaTxt, vector<std::string> options,
                 vector<string> optionsTxt) {
    this -> areaTxt = areaTxt;
    this -> options = options;
    this -> optionsTxt = optionsTxt;
    this -> hasEncounter = hasEncounter;
    for(int i = 0;  i < options.size(); i++){
        isSearched.push_back(false);
    }
    for(int i = 0; i < options.size() * 3; i++){
        items.push_back(item());
    }

}

SubArea::SubArea(vector<item> items, string areaTxt, string areaTxtVisited) {
    this -> items = items;
    this -> options[0] = areaTxt;
    this -> options[1] = areaTxtVisited;
    isSearched.push_back(false);
}

SubArea::SubArea() {
    areaTxt = "NA";
    for(int i = 0; i < 24; i++){
        items.push_back(item());
    }

}

void SubArea::visit(player& p) {
    cout << areaTxt << endl;
    bool active = true;
    while(active){
        char choice = input().actionMenu(options,p,false,true, true);
        if(choice == 'l'){
            return;
        }
        for(int i = 0; i < options.size(); i++){
            if(input().optionsKey[i] == choice){
                search(p,i * 2);
            }
        }
    }
}

void SubArea::search(player& p, int lowerIndex) {
    if(isSearched[lowerIndex]){
        cout << optionsTxt[lowerIndex + 1] << endl;
    }else{
        cout << optionsTxt[lowerIndex] << endl;
        if(items[(lowerIndex/2) * 3].getNumItem() != 0){
            cout << "You found: " << endl;
            for(int i = 0; i < 3; i++){
                if(items[i].getNumItem() != 0){
                    p.getStuff().pickUpItem(items[i]);
                    cout << items[i];
                }
            }
        }
        isSearched[lowerIndex] = true;
    }
}

bool SubArea::getOptionsIsEmpty() {
    return options.empty();
}

void SubArea::setOptionsList(vector<std::string> list) {
    options = list;
    isSearched.clear();
    while(isSearched.size() != options.size()){
        if(isSearched.size() > options.size()){
            isSearched.pop_back();
        }else{
            isSearched.push_back(false);
        }
    }
    while(optionsTxt.size()/2 != options.size()){
        if(optionsTxt.size()/2 > options.size()){
            optionsTxt.pop_back();
            optionsTxt.pop_back();
        }else{
            optionsTxt.push_back("a");
            optionsTxt.push_back("b");
        }
    }
    while(items.size()/3 != options.size()){
        if(items.size()/3 > options.size()){
            items.pop_back();
            items.pop_back();
            items.pop_back();
        }else{
            items.push_back(item());
            items.push_back(item());
            items.push_back(item());
        }
    }
}

bool SubArea::setOptionsText(vector<std::string> list) {
    if(list.size() != options.size() * 2){
        return false;
    }else{
        optionsTxt = list;
        return true;
    }
}

void SubArea::addItem(int choiceIndex, item thing) {
    int minIndex = choiceIndex * 3;
    for(int i = 0; i < 3; i++){
        if(items[minIndex + i].getNumItem() == 0){
            items[minIndex + i] = thing;
            return;
        }
    }
}

void SubArea::setAreaText(std::string text) {
    areaTxt = text;
}

void SubArea::addToOptionsText(std::string text) {
    optionsTxt.push_back(text);
}

void SubArea::addToOptionsList(std::string option) {
    options.push_back(option);
    isSearched.push_back(false);
}

string SubArea::getAreaText() {
    return areaTxt;
}

vector<item> SubArea::getItems() {
    return items;
}

vector<string> SubArea::getOptionsList() {
    return options;
}

vector<string> SubArea::getOptionsText() {
    return optionsTxt;
}

vector<bool> SubArea::getIsSearched() {
    return isSearched;
}

