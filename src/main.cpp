#include <iostream>
#include <string>
#include <cstdlib>
#include "pattern.h"

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
        if (choice == 7) {
            break;
        }
        cout << endl << endl;
    }
}
