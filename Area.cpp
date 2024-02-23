#include "Area.h"


Area::Area(std::string mainText, vector<SubArea> subAreas,
           vector<string> options) {
    this -> mainText = mainText;
    this -> subAreas = subAreas;
    this -> options = options;
}

Area::Area() {}


void Area::run(player& p) {
    bool active = true;
    while(active){
        char choice = input().actionMenu(options,p,true,true,false);
        for(int i = 0; i < options.size(); i++){
            if(input().optionsKey[i] == choice){
                if(subAreas[i].getOptionsIsEmpty()){
                    subAreas[i].search(p,0);
                }else{
                    subAreas[i].visit(p);
                }
            }
        }
        if(choice == 'm'){
            char travel = input().mapMenu(p);
            active = false;
        }
    }
}

void Area::addMainText(std::string text) {
    mainText = text;
}

vector<string> Area::getOptions() {
    return options;
}

void Area::addSubArea(SubArea pSubArea) {
    subAreas.push_back(pSubArea);
}

void Area::setOptionsList(vector<std::string> list) {
    options = list;
}

void Area::addToOptionsList(std::string option) {
    options.push_back(option);
}

vector<SubArea> Area::getSubAreas() {
    return subAreas;
}

string Area::getMainText() {
    return mainText;
}