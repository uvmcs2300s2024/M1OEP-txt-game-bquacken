#include "AreaTemplate.h"

AreaTemplate::AreaTemplate(std::string mainText,vector<SubAreaTemplate> subAreas,
                           vector<string> options) {
    this -> mainText = mainText;
    this -> subAreas = subAreas;
    this -> options = options;
}


void AreaTemplate::run(player& p) {
    bool active = true;
    while(active){
        char choice = input().actionMenu(options,p,true,true,false);
        for(int i = 0; i < options.size(); i++){
            if(optionsKey[i] == choice){
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
