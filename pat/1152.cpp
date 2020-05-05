#include <math.h>

#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

bool judge(int a) {
    if (a < 3) {
        return a > 1;
    }
    if (a % 6 != 1 && a % 6 != 5) {
        return false;
    }
    int b = sqrt(a);
    for (int i = 5; i <= b; i += 6) {
        if (a % i == 0 || a % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// 1152 Google Recruitment
// https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672
int main() {
    int L, K;
    scanf("%d", &L);
    scanf("%d\n", &K);
    // printf("%d %d ", L, K);
    vector<char> nums(L + 1);
    for (int i = 0; i < L; ++i) {
        scanf("%c", &nums[i]);
    }
    // printf("%c\n", nums[0]);
    for (int i = 0; i < L - K + 1; ++i) {
        int a = 0;
        for (int j = 0; j < K; ++j) {
            a += (nums[i + j] - '0') * pow(10, K - j - 1);
        }
        if (judge(a)) {
            for (int j = 0; j < K; ++j) {
                printf("%c", nums[i + j]);
            }
            return 0;
        }
        // printf("bad %d\n", a);
    }
    printf("404\n");
    return 0;
}