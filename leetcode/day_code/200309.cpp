#include <stdarg.h>
#include <algorithm>
#include <cstdio>
#include <map>
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

void findAndDel(int a, vector<int>& v, int left, int right) {
    int mid = (left + right) / 2;
    if (v[mid] == a) {
        int l = v.size();
        for (int i = mid; i < l - 1; ++i) {
            v[i] = v[i + 1];
        }
        v.pop_back();
    } else if (v[mid] > a) {
        findAndDel(a, v, mid + 1, right);
        printf("%d %d\n", left, right);
    } else {
        findAndDel(a, v, left, mid - 1);
        printf("%d %d\n", left, right);
    }

    return;
}

static bool cmp(vector<int> m1, vector<int> m2) { return m1[0] > m2[0]; }
int maxProfit(vector<int>& prices) {
    int ret = 0;
    int l = prices.size();
    if (l <= 0) {
        return ret;
    }
    for (int i = 0; i < prices.size(); ++i) {
        printf("%d ", prices[i]);
    }
    printf("\n");
    vector<int> later(prices.begin() + 1, prices.end());
    for (int i = 0; i < later.size(); ++i) {
        printf("%d ", later[i]);
    }
    printf("\n");

    sort(later.begin(), later.end(), greater<int>());
    for (int i = 0; i < later.size(); ++i) {
        printf("%d ", later[i]);
    }
    printf("\n");

    for (int i = 0; i < l - 1; ++i) {
        int newRet = later[0] - prices[i];
        if (newRet < 0) {
            newRet = 0;
        }
        if (newRet > ret) {
            ret = newRet;
        }
        findAndDel(prices[i + 1], later, 0, later.size());
    }
    printf("%d\n", ret);
    return ret;
}

int main() {
    vector<int> a = initVector(5, 7, 1, 5, 3, 6, 4);
    maxProfit(a);
}