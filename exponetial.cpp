#include "exponetial.h"

int binarySearch_e(const string &text, const vector<int> &suffixArray, char target, int l, int r, bool searchFirst) {
    int res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (text[suffixArray[mid]] == target) {
            res = mid;
            if (searchFirst) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else if (text[suffixArray[mid]] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int Exponential(const string &text, const vector<int> &suffixArray, char target) {
    int n = suffixArray.size();
    int first = -1, last = -1;

    // Exponential search for the first occurrence
    if (text[suffixArray[0]] == target) {
        first = 0;
    } else {
        int i = 1;
        while (i < n && text[suffixArray[i]] <= target) {
            i *= 2;
        }
        first = binarySearch_e(text, suffixArray, target, i / 2, min(i, n - 1), true);
    }

    // Exponential search for the last occurrence

    int left = 0, right = text.length() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (text[suffixArray[mid]] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    last = right;
    if (first == -1 || last == -1) {
        return 0;
    } else {
        return last - first + 1;
    }
}