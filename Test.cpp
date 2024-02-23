#include <ostream>
#include <iostream>
#include <string>

#include "LevelFromFile.h"
#include "item.h"
#include "player.h"
#include "SubArea.h"

bool subAreaTest();

using namespace std;
int main(){

    cout << subAreaTest << endl;
    return 0;
}

bool subAreaTest(){
    bool passed = true;
    player p = player();
    SubArea s1 = SubArea();
    if(s1.getAreaText() != "NA"){
        cout << "Failed empty constructor" << endl;
        passed = false;
    }
    string a = "main txt";
    vector<string> b = {"option 1","option 2","option 3","option 4","option 5"};
    vector<string> c = {"option a1","option b1","option a2","option b2",
                        "option a3","option b","option a4","option b4",
                        "option a5","option b5"};
    s1.setOptionsList(b);
    if(!s1.setOptionsText(c)){
        cout << "Failed setOptionsList test" << endl;
        passed = false;
    }
    s1.addItem(1,item(bomb,2));
    if(s1.getItems()[3].getNumItem() == 0){
        cout << "Failed addItem first test" << endl;
        passed = false;
    }
    s1.addItem(1,item(coin,5));
    if(s1.getItems()[4].getNumItem() != 5){
        cout << "Failed addItem cluttered choiceIndex test" << endl;
        passed = false;
    }
    b.pop_back();
    if(s1.getOptionsText().size() != 8 || s1.getItems().size() != 12){
        cout << "Failed options auto-resize" << endl;
    }
    return passed;
}

bool areaTest(){
    return true;
}