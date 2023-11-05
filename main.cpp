#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include "openfile.h"
#include "binary_ternary.h"
#include "exponetial.h"
#include "interpolation.h"

using namespace std;

int build();

int main() {
    int answer = 2;
    if(answer == 1) build();
    else if (answer == 2) {
        string fastaFilename = "gene.fa"; // 替换成FASTA文件名
        string sequence = readFasta(fastaFilename);

        // 从文件读取后缀数组
        string suffixArrayFilename = "gene.txt";  // 后缀数组文件名
        vector<int> suffixArray = readSuffixArrayFromFile(suffixArrayFilename);

        char target = 'C';
        const int num_trials = 10000;
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < num_trials; ++i) {
            interpolation(sequence, suffixArray, target);
        }
        int occurrence = interpolation(sequence, suffixArray, target);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "The character '" << target << "' appears " << occurrence << " times." << endl;
        cout << "The function took an average of " << duration.count() / static_cast<double>(num_trials)
             << " microseconds over " << num_trials << " trials." << endl;
    }

    return 0;
}

vector<int> buildSuffixArray(const string& text) {
    int n = text.length();
    vector<int> suffixArray(n);
    for (int i = 0; i < n; ++i) {
        suffixArray[i] = i;
    }

    sort(suffixArray.begin(), suffixArray.end(), [&text](int a, int b) {
        return text.substr(a) < text.substr(b);
    });

    return suffixArray;
}

// 输出后缀数组到文件
void writeSuffixArrayToFile(const vector<int>& suffixArray, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Cannot open file: " << filename << endl;
        exit(1);
    }

    for (int i : suffixArray) {
        file << i << "\n";
    }
}

int build() {
    string fastaFilename = "test.fa";  // 替换成FASTA文件名
    string sequence = readFasta(fastaFilename);

    // 构建后缀数组
    vector<int> suffixArray = buildSuffixArray(sequence);

    // 将后缀数组输出到文件
    string outputFilename = "test.txt";  // 输出文件名
    writeSuffixArrayToFile(suffixArray, outputFilename);

    /* 打印后缀数组
    for (int i : suffixArray) {
        cout << i << " ";
    }
    cout << endl;*/

    return 0;
}
