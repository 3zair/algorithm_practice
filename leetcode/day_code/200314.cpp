#include <stdarg.h>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> initVector(int count, ...) {
    vector<int> a;
    va_list args;
    va_start(args, count);
    while (count--) {
        a.push_back(va_arg(args, int));
    }
    va_end(args);

    return a;
}

int lengthOfLIS(vector<int>& nums) {
    int l = nums.size();
    if (l <= 0) {
        return 0;
    }
    vector<int> dp;
    for (int i = 0; i < l; ++i) {
        dp.emplace_back(1);
        for (int j = 0; j <= i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < dp.size(); ++i) {
        if (max < dp[i]) {
            max = dp[i];
        }
    }
    printf("%d\n", max);
    return max;
}
int main() {
    vector<int> a = initVector(8, 10, 9, 2, 5, 3, 7, 101, 18);
    lengthOfLIS(a);
}