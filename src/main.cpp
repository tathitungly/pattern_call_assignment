#include <iostream>
#include <string>
#include <cstdlib>
#include "patternfactory.h"
#include "patterndatabase.h"

using namespace std;

int main( int argc, const char* argv[] )
{
    bool isContinue = true;
    string inputStr = "";
    PatternDatabase patternDatabase;
    while (isContinue) {
        cout << "Hello! What would you like to do?" << endl
                  << endl
                  << "1. Enter a new pattern call" << endl
                  << "2. Get a pattern call" << endl
                  << "3. List all pattern calls with a specified name" << endl
                  << "4. List all pattern calls with a specified path" << endl
                  << "5. List all pattern calls which are skipped" << endl
                  << "6. List all pattern calls which are not skipped" << endl
                  << "7. Export to a file" << endl
                  << "8. Import from a file" << endl
                  << "9. Exit" << endl << endl;
        cout << "Your choice? ";
        getline(cin, inputStr);
        int choice = atoi(inputStr.c_str());
        try {
            switch (choice) {
            case 1: {
                    cout << endl << endl << "Please enter pattern data:"
                         << endl << "(e.g: 42;myPattern;src/patterns/Functional.pat;1 )" << endl;
                    cout << "Pattern data: ";
                    getline(cin, inputStr);
                    Pattern *pattern = PatternFactory::stringToPattern(inputStr);
                    if (pattern != NULL) {
                        patternDatabase.addPattern(pattern);
                        cout << "Pattern inserted: " << inputStr << endl;
                    } else {
                        cout << "Wrong format." << endl;
                    }
                }
                break;
            case 2: {
                    cout << endl << endl << "Please enter pattern ID: ";
                    getline(cin, inputStr);
                    choice = atoi(inputStr.c_str());
                    Pattern *pattern = patternDatabase.getPatternById(choice);
                    if (pattern != NULL) {
                        cout << "Pattern data:" << endl << pattern->toString();
                    } else {
                        cout << "Cannot find pattern with input ID." << endl;
                    }
                }
                break;
            case 3: {
                    cout << endl << endl << "Please enter name for filter: ";
                    getline(cin, inputStr);
                    std::vector<Pattern*> result = patternDatabase.getPatternsByName(inputStr);
                    for(Pattern *pat : result) {
                        cout << pat->toString() << endl;
                    }
                }
                break;
            case 4: {
                    cout << endl << endl << "Please enter path for filter: ";
                    getline(cin, inputStr);
                    std::vector<Pattern*> result = patternDatabase.getPatternsByPath(inputStr);
                    for(Pattern *pat : result) {
                        cout << pat->toString() << endl;
                    }
                }
                break;
            case 5: {
                    std::vector<Pattern*> result = patternDatabase.getPatternsByFlag(false);
                    for(Pattern *pat : result) {
                        cout << pat->toString() << endl;
                    }
                }
                break;
            case 6: {
                    std::vector<Pattern*> result = patternDatabase.getPatternsByFlag(true);
                    for(Pattern *pat : result) {
                        cout << pat->toString() << endl;
                    }
                }
                break;
            case 7: {
                    cout << endl << endl << "Please enter file name for export: ";
                    getline(cin, inputStr);
                    patternDatabase.exportDatabase(inputStr);
                }
                break;
            case 8: {
                    cout << endl << endl << "Please enter file name for import: ";
                    getline(cin, inputStr);
                    patternDatabase.importDatabase(inputStr);
                }
                break;
            case 9: cout << endl << "Bye!!" << endl; return 0;
            }
        } catch (const char* msg) {
            cout << msg << endl;
        }
        cout << endl << endl;
    }
}
