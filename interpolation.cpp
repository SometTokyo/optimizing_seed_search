#include "interpolation.h"

int binarySearch_i(const string &text, const vector<int> &suffixArray, int left, int right, int target, bool searchFirst) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (text[suffixArray[mid]] > target || (searchFirst && text[suffixArray[mid]] >= target)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return searchFirst ? left : right;
}

int calculateCutIndex(const string &text, const vector<int> &suffixArray, int left, int right, int target, int i) {
    int li = (text[suffixArray[right]] - text[suffixArray[left]]);
    int Ni = (target - text[suffixArray[left]]);
    int C_int = left + ((right - left) * Ni )/ li;
    int C_bin = (left + right) / 2;
    double Delta_i = Ni* sqrt(li) + sqrt(Ni);
    int C_plus = static_cast<int>(C_int + Delta_i);
    int C_minus = static_cast<int>(C_int - Delta_i);

    if (i % 3 == 1) return std::min(C_plus, right - 1);
    if (i % 3 == 2) return std::max(C_minus, left + 1);
    return C_bin;  // Binary cut for i % 3 == 0
}


int interpolation(const string &text, const vector<int> &suffixArray, int target) {
    int left = 0, right = suffixArray.size() - 1;
    int i = 0;
    while (left <= right && target >= text[suffixArray[left]] && target <= text[suffixArray[right]]) {
        // Estimate the position using the formula for interpolation search
        int pos = calculateCutIndex(text, suffixArray,left, right, target, i);

        // Ensure pos is within boundaries
        if (pos < 0 || pos >= suffixArray.size()) {
            break;
        }

        if (text[suffixArray[pos]] == target) {
            // Switch to binary search to find the boundaries
            int term1 = pos;
            int leftIdx = binarySearch_i(text, suffixArray, left, term1, target, true);
            left = pos;
            int rightIdx = binarySearch_i(text, suffixArray, left, right, target, false);
            return rightIdx - leftIdx + 1;  // Return the range of matched characters
        } else if (text[suffixArray[pos]] < target) {
            left = pos + 1;
            i++;
        } else {
            right = pos - 1;
            i++;
        }
    }
    return -1;
}