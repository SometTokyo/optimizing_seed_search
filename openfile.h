#ifndef RESEARCHALGO_OPENFILE_H
#define RESEARCHALGO_OPENFILE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<int> readSuffixArrayFromFile(const string& filename);

string readFasta(const string& filename);

#endif //RESEARCHALGO_OPENFILE_H

