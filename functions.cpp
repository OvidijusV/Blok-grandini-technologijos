#include "declarations.h"

void checkChoice(int &choice) {
    while(choice != 1 && choice != 2){
        cout << "Wrong choice. It can be only (1) or (2)." << endl;
        cout << "Repeat your choice: ";
        cin >> choice; 
    }
};

string readFile(){
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
    inp.close();

    return input;

};

void hashFunction(string inputHash){
    int wordsCounter = 1;
    const char *str = inputHash.c_str();

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ')
            wordsCounter++;
    }

    cout << inputHash << endl;
    cout << wordsCounter;
};