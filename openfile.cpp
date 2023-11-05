#include "openfile.h"

vector<int> readSuffixArrayFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file: " << filename << endl;
        exit(1);
    }
    vector<int> suffixArray;
    int value;
    while (file >> value) {
        suffixArray.push_back(value);
    }
    return suffixArray;
}

string readFasta(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Cannot open file: " << filename << endl;
        exit(1);
    }
    string line, sequence;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '>') continue;
        sequence += line;
    }
    return sequence;
}