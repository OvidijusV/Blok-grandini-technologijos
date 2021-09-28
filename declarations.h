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
using namespace std;

void checkChoice(int &choice);
string readFile(string fileName);
int countWords(string str);
void generateFile(string fileName, int numOfChar);
void hashFunction(string inputHash);


#endif