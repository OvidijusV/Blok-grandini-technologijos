#include "declarations.h"

int main(){

    int choice;
    cout << "***** HASH GENERATOR *****" << endl;
    cout << "1. Read text from file" << endl << "2. Input text here" << endl << "Your choice(1/2): ";
    cin >> choice;
    checkChoice(choice);

    if(choice = 1){
        readFile();
    } 
    else {

    }
}