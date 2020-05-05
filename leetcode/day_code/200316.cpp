#include <cstdio>
#include <string>
using namespace std;

string compressString(string S) {
    string newStr;
    char curS = S[0];
    int count = 1;
    newStr += (curS);
    for (int i = 1; i < S.size(); ++i) {
        if (S[i] == curS) {
            count++;
        } else {
            newStr += to_string(count);
            curS = S[i];
            newStr += curS;
            count = 1;
            if (newStr.size() > S.size()) {
                return S;
            }
        }
    }
    newStr += to_string(count);
    if (newStr.size() >= S.size()) {
        return S;
    }
    return newStr;
}
int main() {}