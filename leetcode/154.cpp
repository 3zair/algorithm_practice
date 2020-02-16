#include <string.h>
#include <iostream>
#include <map>
using namespace std;

// 1.气球的最大数量
int maxNumberOfBalloons(string text) {
    string base = "balloon";
    int num[5] = {0};

    for (int i = 0; i < text.length(); ++i) {
        // printf("%c",text[i]);
        if (text[i] == 'b') {
            num[0]++;
            continue;
        }
        if (text[i] == 'a') {
            num[1]++;
            continue;
        }
        if (text[i] == 'l') {
            num[2]++;
            continue;
        }
        if (text[i] == 'o') {
            num[3]++;
            continue;
        }
        if (text[i] == 'n') {
            num[4]++;
            continue;
        }
    }

    int count = num[0];
    num[2] = num[2] / 2;
    num[3] = num[3] / 2;
    for (int j = 1; j < 5; ++j) {
        if (count > num[j]) {
            count = num[j];
        }
    }

    return count;
}

int main() { printf("%d\n", maxNumberOfBalloons("nlaebolko")); }
