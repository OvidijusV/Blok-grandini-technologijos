#ifndef DELCARATIONS_H
#define DELCARATIONS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <bitset>
#include <math.h>
#include <ctime>
#include <chrono>
using namespace std;

class Timer {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
        Timer() : start{std::chrono::high_resolution_clock::now()} {}
        void reset() {
        start = std::chrono::high_resolution_clock::now();
        }
        double elapsed() const {
        return std::chrono::duration<double>
        (std::chrono::high_resolution_clock::now() - start).count();
        }
};

void checkChoice(int &choice);
string readFile(string fileName);
int countWords(string str);
void generateFile(string fileName, int numOfChar);
string hashFunction(string inputHash);
void hashKonstitucija();
void collisionTest();
void avalancheTest();


#endif