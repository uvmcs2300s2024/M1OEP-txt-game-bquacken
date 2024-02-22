#include <iostream>
#include <fstream>
#include "LevelFromFile.h"

AreaTemplate LevelFromFile::buildArea(std::string file) {
    ifstream inFile("../" + file);

    string line;
    getline(inFile,line);
    AreaTemplate area = AreaTemplate();

    if(line == ">A"){
        getline(inFile,line);
        while(line != "<A"){
            if(line == ">S"){
                area.addSubArea(buildSubArea(inFile));
            }else if(line == ">O"){
                area.addSubArea(buildOption(inFile));
            }else if(line == "-L"){
                area.setOptionsList(readOptions(inFile));
            }else if(line == "-T"){
                area.addMainText(readText(inFile));
            }
        }
    }
}

SubAreaTemplate LevelFromFile::buildSubArea(std::ifstream &inFile) {
    string line;
    SubAreaTemplate subarea = SubAreaTemplate();
    getline(inFile,line);
    subarea.setAreaText(readText(inFile));
    bool consecutiveItems = false;
    int itemIndex = -1;
    while(line != "<S"){
        if(line == "-T"){
            consecutiveItems = false;
            subarea.addToOptionsText(readText(inFile));
        }else if(line == "-L"){
            consecutiveItems = false;
            subarea.setOptionsList(readOptions(inFile));
        }else if(line =="-I"){
            if(consecutiveItems){

            }else{
                itemIndex++;
                subarea.addItem(itemIndex, readItem(inFile));
            }
            consecutiveItems = true;
        }
    }
    return subarea;
}

SubAreaTemplate LevelFromFile::buildOption(std::ifstream &inFile) {
    string line;
    SubAreaTemplate o;
    getline(inFile,line);
    if(line == "-T"){
        o.addToOptionsText(readText(inFile));
    }else if(line == "-I"){
        o.addItem(0,readItem(inFile));
    }
}

item LevelFromFile::readItem(std::ifstream &inFile) {
    string line;
    getline(inFile,line);
    int type = stoi(line);
    getline(inFile,line);
    int amount = stoi(line);
    getline(inFile,line);
    return item(type,amount);
}

vector<string> LevelFromFile::readOptions(std::ifstream &inFile) {
    string line;
    vector<string> list;
    getline(inFile,line);
    while(line != "_L"){
        list.push_back(line);
        getline(inFile,line);
    }
    return list;
}

string LevelFromFile::readText(std::ifstream &inFile) {
    string line;
    getline(inFile,line);
    string mainText;
    while(line != "_T"){
        mainText += line + "\n";
        getline(inFile,line);
    }
    return mainText;
}

