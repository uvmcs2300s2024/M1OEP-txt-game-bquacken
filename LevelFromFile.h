/**This is the code that reads a level from a text file there are a few
 * special characters that are used to denote what is being added
 * '>' is the open character for the area(A) subarea(S) option(O)
 * '<' is the close for those three
 * '-' is the open character for item(I) option list(L) text(T)
 * '_' is the close for those three
 * if you want an area to be dark add '-D' and then "true" on the next line
 * look at the example document for the full formatting guide
 */
#ifndef TXT_GAME_BQUACKEN_LEVELFROMFILE_H
#define TXT_GAME_BQUACKEN_LEVELFROMFILE_H

#include <iostream>
#include <vector>
#include "Area.h"
using std::string,std::cout,std::endl;

class LevelFromFile{
public:
    /**
     * takes a file with specific formatting and
     * creates a level of the text game
     * @param file the file that is read from
     */
    Area buildArea(string file);

    /**
     * creates a subarea
     * @param inFile the file object that is read from
     * @return a complete subarea
     */
    SubArea buildSubArea(ifstream& inFile);

    /**
     * makes a version of a subarea that has no options
     * within it this is the campsite in the example text file
     * @param inFile the file object that is read from
     * @return a simple version of a subarea
     */
    SubArea buildOption(ifstream& inFile);

    /**
     * reads text until the character _T is read
     * @param inFile the file read from
     * @return a string of text
     */
    string readText(ifstream& inFile);

    /**
     * reads a list of options using _L as the delimiter
     * @param inFile the file read from
     * @return a vector of strings that is turned into an option
     * menu
     */
    vector<string> readOptions(ifstream& inFile);

    /**
     * reads and creates an item object using the id
     * of the itemType and the amount as the second line
     * @param inFile the file object that is read from
     * @return an item object
     */
    item readItem(ifstream& inFile);

};

#endif //TXT_GAME_BQUACKEN_LEVELFROMFILE_H
