#include <cstdio>
#include <map>
#include <string>
using namespace std;

int longestPalindrome(string s) {
    map<char, int> cMap;
    for (int i = 0; i < 26; ++i) {
        cMap['a' + i] = 0;
        cMap['A' + i] = 0;
    }
    for (int i = 0; i < s.size(); ++i) {
        cMap[s[i]] += 1;
    }

    bool flag = false;
    int maxLen = 0;
    for (int i = 0; i < 26; ++i) {
        if (cMap['a' + i] % 2 == 0) {
            maxLen += cMap['a' + i];
        } else {
            flag = true;
            maxLen += cMap['a' + i] - 1;
        }
        if (cMap['A' + i] % 2 == 0) {
            maxLen += cMap['A' + i];
        } else {
            flag = true;
            maxLen += cMap['A' + i] - 1;
        }
    }
    if (flag) {
        maxLen += 1;
    }

    return maxLen;
}