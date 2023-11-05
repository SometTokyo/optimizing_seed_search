#ifndef RESEARCHALGO_INTERPOLATION_H
#define RESEARCHALGO_INTERPOLATION_H

#include <vector>
#include <string>
#include <cmath>

using namespace std;

int binarySearch_i(const string &text, const vector<int> &suffixArray, int left, int right, int target, bool searchFirst);

int interpolation(const string &text, const vector<int> &suffixArray, int target);

int calculateCutIndex(const string &text, const vector<int> &suffixArray, int left, int right, int target, int i);

#endif //RESEARCHALGO_INTERPOLATION_H
