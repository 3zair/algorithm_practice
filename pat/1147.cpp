#include <cstdio>
#include <vector>
using namespace std;

vector<int> a(1000);
int m, n;
void postOrder(int i) {
    if (i > n) return;
    postOrder(i * 2);
    postOrder(i * 2 + 1);
    printf("%d%s", a[i], i == 1 ? "\n" : " ");
}

// 1147 Heaps
// https://pintia.cn/problem-sets/994805342720868352/problems/994805342821531648
// heap 堆
int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; ++i) {
        bool minFlag = true, maxFlag = true;

        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[j]);
            // printf("%d ", a[j]);
        }
        for (int j = 2; j <= n; ++j) {
            if (a[j] > a[j / 2]) maxFlag = false;
            if (a[j] < a[j / 2]) minFlag = false;
        }
        if (maxFlag)
            printf("Max Heap\n");
        else if (minFlag)
            printf("Min Heap\n");
        else
            printf("Not Heap\n");

        postOrder(1);
    }
    return 0;
}