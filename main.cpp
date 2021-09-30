#include "declarations.h"

int main(){

    int choice;
    cout << "***** HASH GENERATOR *****" << endl;
    cout << "1. Read text from file" << endl << "2. Input text here" << endl << "3. Test1"<< endl << "4. Benchmark hashing konstitucija.txt" << endl << "5. Collision test" << endl << "6. Avalanche test" << endl << "Your choice: ";
    cin >> choice;
    cin.ignore();
    checkChoice(choice);

    if(choice == 1){
        string fileName;
        cout << "Enter file name: ";
        cin >> fileName;
        fileName = fileName + ".txt";
        hashFunction(readFile(fileName));
    } 
    else if(choice == 2){
        string input;
        cout << "Enter your text: ";
        getline (cin, input);
        hashFunction(input);

    }
    else if(choice == 3){
        generateFile("testRandom2000a.txt", 2000);
        generateFile("testRandom2000b.txt", 2000);
        hashFunction(readFile("test1a.txt"));
        hashFunction(readFile("test1b.txt"));
        hashFunction(readFile("testRandom2000a.txt"));
        hashFunction(readFile("testRandom2000b.txt"));
        hashFunction(readFile("test1500a.txt"));
        hashFunction(readFile("test1500b.txt"));
        hashFunction(readFile("testempty.txt"));
    }
    else if(choice == 4){
        hashKonstitucija();
    }
    else if(choice == 5){
        collisionTest();
    }
    else if(choice == 6){
        avalancheTest();
    }

    return 0;
}