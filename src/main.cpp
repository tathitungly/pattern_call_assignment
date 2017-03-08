#include <iostream>
#include <string>
#include <cstdlib>
#include "patternfactory.h"

using namespace std;

int main( int argc, const char* argv[] )
{
    bool isContinue = true;
    string inputStr = "";
    while (isContinue) {
        cout << "Hello! What would you like to do?" << endl
                  << endl
                  << "1. Enter a new pattern call" << endl
                  << "2. Delete a pattern call" << endl
                  << "3. List all pattern calls with a specified name" << endl
                  << "4. List all pattern calls with a specified path" << endl
                  << "5. List all pattern calls which are skipped" << endl
                  << "6. List all pattern calls which are not skipped" << endl
                  << "7. Exit" << endl << endl;
        cout << "Your choice? ";
        getline(cin, inputStr);
        int choice = atoi(inputStr.c_str());
        switch (choice) {
        case 1:
            cout << endl << endl << "Please enter pattern data:"
                 << endl << "(e.g: 42;myPattern;src/patterns/Functional.pat;false )" << endl;
            cout << "Pattern data: ";
            getline(cin, inputStr);
            try {
                Pattern newPattern = PatternFactory::stringToPattern(inputStr);
                cout << newPattern.toString() << endl;
            } catch (const char* msg) {
                cout << msg << endl;
            }
            break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: cout << endl << "Bye!!" << endl; return 0;
        }
        cout << endl << endl;
    }
}
