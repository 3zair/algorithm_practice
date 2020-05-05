#include <cstdio>
#include <vector>
using namespace std;

int add(int a) {
    int y = 0, ret = 0;
    while (a != 0) {
        y = a % 10;
        a = a / 10;
        ret += y;
    }

    return ret;
}
int movingCount(int m, int n, int k) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int ia = add(i);
        if (ia > k) {
            continue;
        }
        for (int j = 0; j < m; ++j) {
            int ja = add(j);
            if (ja > k) {
                continue;
            }
            if (ja + ia <= k) {
                printf("%d %d\n", i, j);
                count++;
            }
        }
    }

    return count;
}

int main() { movingCount(16, 8, 4); }