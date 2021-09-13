#include "declarations.h"

void checkChoice(int &choice) {
    while(choice != 1 && choice != 2){
        cout << "Wrong choice. It can be only (1) or (2)." << endl;
        cout << "Repeat your choice: ";
        cin >> choice; 
    }
}

void readFile(){
    string fileName, input;

    cout << "Enter file name: ";
    cin >> fileName;
    fileName = fileName + ".txt";

    ifstream inp;

    try {
        inp.open(fileName);
        if(!inp.is_open())
            throw 1;
        else cout << "Reading file..." << endl;
    }
    catch (int error) {
        cout << "Could not find file named " << fileName << endl << "Closing the program...";
        exit(0);
    }

    getline(inp, input);
    cout << "Text found: " << input << endl;

}