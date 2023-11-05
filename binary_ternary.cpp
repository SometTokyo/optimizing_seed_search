#include "binary_ternary.h"

int binary(const string &text, const vector<int> &suffixArray, char target) {
    int left = 0, right = text.length() - 1, mid;

    // 找到第一个目标字符
    int first = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (text[suffixArray[mid]] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    first = left;

    // 找到最后一个目标字符
    int last = -1;
    left = 0, right = text.length() - 1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (text[suffixArray[mid]] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    last = right;

    // 计算字符出现次数
    if (first <= last) {
        return last - first + 1;
    } else {
        return 0;
    }
}

int ternary(const string &text, const vector<int> &suffixArray, char target) {
    int left = 0, right = text.length() - 1;
    int first = -1, last = -1;

    // 找到第一个目标字符
    while (left < right) {
        int m1 = left + (right - left) / 3;
        int m2 = right - (right - left) / 3;

        if (text[suffixArray[m1]] >= target) {
            right = m1;
        } else if (text[suffixArray[m2]] < target) {
            left = m2 + 1;
        } else {
            left = m1 + 1;
            right = m2;
        }
    }
    if (text[suffixArray[left]] == target) first = left;
    if (first == -1) return 0;

    // 找到最后一个目标字符
    left = 0, right = text.length() - 1;
    while (left < right) {
        int m1 = left + (right - left) / 3;
        int m2 = right - (right - left) / 3;

        if (text[suffixArray[m1]] > target) {
            right = m1;
        } else if (text[suffixArray[m2]] <= target) {
            left = m2;
        } else {
            left = m1 + 1;
            right = m2;
        }
    }
    if (text[suffixArray[right-1]] == target) last = right;

    // 计算字符出现次数
    return last - first;
}