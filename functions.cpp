#include "declarations.h"

void checkChoice(int &choice) {
    while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5){
        cout << "Wrong choice. It can be only (1) or (2)." << endl;
        cout << "Repeat your choice: ";
        cin >> choice;
        
    }
};

string readFile(string fileName){
    string input;

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
    cout << "Input found: " << input << endl;
    inp.close();

    return input;

};

int countWords(string str)
{
    
    stringstream counter(str);
    string word;
  
    int wordsCount = 0;
    while (counter >> word)
        wordsCount++;
    return wordsCount;
}

string HexToBin(string hexdec)
{
    long int i = 0;
 
    string binary;
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            binary += "0000";
            break;
        case '1':
            binary += "0001";
            break;
        case '2':
            binary += "0010";
            break;
        case '3':
            binary += "0011";
            break;
        case '4':
            binary += "0100";
            break;
        case '5':
            binary += "0101";
            break;
        case '6':
            binary += "0110";
            break;
        case '7':
            binary += "0111";
            break;
        case '8':
            binary += "1000";
            break;
        case '9':
            binary += "1001";
            break;
        case 'A':
        case 'a':
            binary += "1010";
            break;
        case 'B':
        case 'b':
            binary += "1011";
            break;
        case 'C':
        case 'c':
            binary += "1100";
            break;
        case 'D':
        case 'd':
            binary += "1101";
            break;
        case 'E':
        case 'e':
            binary += "1110";
            break;
        case 'F':
        case 'f':
            binary += "1111";
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                 << hexdec[i];
        }
        i++;
    }
    return binary;
}

string BinToHex(string hexdec)
{
 
    string hexas;
 
    if(hexdec == "0000")
        hexas = "0";
    else if (hexdec == "0001")
        hexas = "1";
    else if (hexdec == "0010")
        hexas = "2";
    else if (hexdec == "0011")
        hexas = "3";
    else if (hexdec == "0100")
        hexas = "4";
    else if (hexdec == "0101")
        hexas = "5";
    else if (hexdec == "0110")
        hexas = "6";
    else if (hexdec == "0111")
        hexas = "7";
    else if (hexdec == "1000")
        hexas = "8";
    else if (hexdec == "1001")
        hexas = "9";
    else if (hexdec == "1010")
        hexas = "a";
    else if (hexdec == "1011")
        hexas = "b";
    else if (hexdec == "1100")
        hexas = "c";
    else if (hexdec == "1101")
        hexas = "d";
    else if (hexdec == "1110")
        hexas = "e";
    else if (hexdec == "1111")
        hexas = "f";

    return hexas;
}

void generateFile(string fileName, int numOfChar){


    ofstream generate;
    generate.open(fileName);

    string s;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < numOfChar; ++i) {
        s+= alphanum[rand() % (sizeof(alphanum) - 1)];
    };

    generate << s;
    generate.close();
};



string hashFunction(string inputHash){

    //cout << "Hashing input: " << inputHash << endl;
    int secret = 1673;

    unsigned int mixing = 5761;
    for(int i = 0; i < inputHash.size(); i++){
        mixing = mixing * inputHash.at(i) - secret * inputHash.length() + inputHash.front() - (mixing % 10);
    }
    //cout << mixing << endl;

    string mixingString = to_string(mixing);
    
    int variable = 7;

    while(mixingString.size() != 64){
        int a = mixing / variable - secret / variable; 
        mixingString += to_string(a % 10);
        variable++;
    };
    
    //cout << mixingString << endl;

    bitset<256> initialSet(HexToBin(mixingString));

    string binaryToHex;

    for (int j = 0; j < initialSet.size(); j += 4) {
        string converting;
        converting = initialSet.flip().to_string().substr(j, 4);   // binary padalinam po 4
        binaryToHex += BinToHex(converting);
    
    };
    //cout << "Hex: " << binaryToHex << endl;
    return binaryToHex;
};

void hashKonstitucija(){

    string line;

    ifstream konstitucija;

    try
    {
        string pavadinimas = "konstitucija.txt";
        konstitucija.open(pavadinimas);
        if(!konstitucija.is_open())
            throw 1;
        else cout << "Reading file..." << endl;
    }
    catch(int error)
    {
        std::cout << "Could not find file named konstitucija.txt" << endl;
        cout << "Closing the program...";
        exit(0);
    }

    double timeSpent = 0;
    int lines = 0;
    while(true){
        getline(konstitucija, line);
        Timer t;
        hashFunction(line);
        timeSpent += t.elapsed();
        lines++;
        t.reset();

        if(konstitucija.eof())
            break;
    
    };

    cout << "Time spent hashing every line of file konstitucija.txt: " << timeSpent << "s." << endl;
    cout << "Number of lines hashed: " << lines;
};

void collisionTest(){

    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    int numOfCollisions = 0;

    for(int i = 0; i < 25000; i++){
        string pair1;
        string pair2;

        for (int i = 0; i < 10; ++i) {
            pair1+= alphanum[rand() % (sizeof(alphanum) - 1)];
            pair2+= alphanum[rand() % (sizeof(alphanum) - 1)];
        };
        if(hashFunction(pair1) == hashFunction(pair2))
            numOfCollisions++;

        pair1.clear();
        pair2.clear();
    };

    for(int i = 0; i < 25000; i++){
        string pair1;
        string pair2;

        for (int i = 0; i < 100; ++i) {
            pair1+= alphanum[rand() % (sizeof(alphanum) - 1)];
            pair2+= alphanum[rand() % (sizeof(alphanum) - 1)];
        };
        if(hashFunction(pair1) == hashFunction(pair2))
            numOfCollisions++;

        pair1.clear();
        pair2.clear();
    };

    for(int i = 0; i < 25000; i++){
        string pair1;
        string pair2;

        for (int i = 0; i < 500; ++i) {
            pair1+= alphanum[rand() % (sizeof(alphanum) - 1)];
            pair2+= alphanum[rand() % (sizeof(alphanum) - 1)];
        };
        if(hashFunction(pair1) == hashFunction(pair2))
            numOfCollisions++;

        pair1.clear();
        pair2.clear();
    };

    for(int i = 0; i < 25000; i++){
        string pair1;
        string pair2;

        for (int i = 0; i < 1000; ++i) {
            pair1+= alphanum[rand() % (sizeof(alphanum) - 1)];
            pair2+= alphanum[rand() % (sizeof(alphanum) - 1)];
        };
        if(hashFunction(pair1) == hashFunction(pair2))
            numOfCollisions++;

        pair1.clear();
        pair2.clear();
    };

    cout << "Number of collisions found: " << numOfCollisions;
}