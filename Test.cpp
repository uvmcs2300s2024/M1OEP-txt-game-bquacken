#include <ostream>
#include <iostream>
#include <string>

#include "LevelFromFile.h"
#include "item.h"
#include "player.h"
#include "SubArea.h"

bool subAreaTest();
bool areaTest();
bool levelFromFileTest(string file);
using namespace std;
int main(){


    subAreaTest();
    areaTest();
    levelFromFileTest("testing.txt");
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
                        "option a3","option b4","option a4","option b4",
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
    s1.setOptionsList(b);
    if(s1.getOptionsText().size() != 8 || s1.getItems().size() != 12){
        cout << "Failed options auto-resize" << endl;
    }

    //play test
    SubArea s2 = SubArea("hello","hey again");
    if(s2.getOptionsText()[1] != "hey again"){
        cout << "failed simple constructor" << endl;
        passed = false;
    }
    SubArea s3 = SubArea(a,b,c);
    if(s3.getAreaText() != a || s3.getOptionsList()[0] != b[0] ||
       s3.getOptionsText()[1] != c[1]){
        cout << "Failed complex constructor" << endl;
        passed = false;
    }
    return passed;
}

bool areaTest(){
    bool passed = true;
    string a = "Main text";
    vector<SubArea> b = {SubArea(),SubArea(),SubArea()};
    vector<string> c = {"option 1", "option 2", "option 3"};
    Area a1 = Area();
    Area a2 = Area(a,b,c);
    if(a2.getMainText() != a){
        cout << "Failed constructor test" << endl;
        passed = false;
    }
    a1.setMainText(a);
    if(a1.getMainText() != a){
        cout << "Failed setMainText" << endl;
        passed = false;
    }
    a1.setOptionsList(c);
    for(SubArea s:b){
        a1.addSubArea(s);
    }
    if(a1.getSubAreas().size() != 3){
        cout << "Failed addSubArea" << endl;
        passed = false;
    }
    c.pop_back();
    if(a1.setOptionsList(c)){
        cout << "Failed setOptionsList" << endl;
        passed = false;
    }
    return passed;
}

bool levelFromFileTest(string file){
    bool passed = true;
    Area a = LevelFromFile().buildArea(file);
    if(a.getSubAreas().size() != 2){
        passed = false;
        cout << "Failed number of subareas" << endl;
    }
    if(a.getSubAreas()[0].getOptionsList()[1] != "is"){
        passed = false;
        cout << "Failed optionList for subArea 1" << endl;
    }
    if(a.getMainText() != "Main text\n"){
        passed = false;
        cout << "Failed MainText" << endl;
    }
    if(a.getOptions()[1] != "b"){
        passed = false;
        cout << "Failed optionsList" << endl;
    }
    if(!a.getSubAreas()[1].getOptionsIsEmpty()){
        passed = false;
        cout << "Failed buildOption" << endl;
    }
    if(a.getSubAreas()[1].getItems()[0].getItemID() != 0){
        passed = false;
        cout << "Failed item in buildOption" << endl;
    }
    if(a.getSubAreas()[0].getItems()[1]. getNumItem() != 3){
        cout << "Failed multiple items in buildSubArea" << endl;
        passed = false;
    }
    player p = player();
    a.run(p);
    return passed;
}