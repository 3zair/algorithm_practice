#include <cstdio>
using namespace std;

int work(int i, int n, int arr[]) {
    if (i > n) return 0;

    if (i == n) return 1;

    arr[i] = work(i + 1, n, arr) + work(i + 2, n, arr);

    return arr[i];
}

int climbStairs(int n) {
    int arr[n + 1];
    int ret = work(0, n, arr);
    // printf("%d\n", ret);

    return ret;
}

int main() {
    climbStairs(3);
    return 0;
}