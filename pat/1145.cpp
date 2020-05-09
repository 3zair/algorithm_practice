#include <math.h>

#include <cstdio>
#include <vector>
using namespace std;

bool isPrime(int a) {
    int aa = sqrt(a);
    if (a <= 1) return false;
    for (int i = 2; i <= aa; ++i)
        if (a % i == 0) return false;
    return true;
}

// 1145 Hashing - Average Search Time
// https://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744
// 哈希， 平方检测法(Quadratic probing) 解决冲突：
int main() {
    int tSize, n, m;
    scanf("%d %d %d", &tSize, &n, &m);
    while (!isPrime(tSize)) tSize++;
    vector<int> h(tSize);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        bool flag = false;
        for (int j = 0; j < n; j++) {
            int p = (a + j * j) % tSize;
            if (h[p] == 0) {
                h[p] = a;
                flag = true;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", a);
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int b;
        scanf("%d", &b);
        for (int j = 0; j <= tSize; j++) {
            ans++;
            int p = (b + j * j) % tSize;
            if (h[p] == b || h[p] == 0) break;
        }
    }

    printf("%.1lf\n", ans * 1.0 / m);
    return 0;
}