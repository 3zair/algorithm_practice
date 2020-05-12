#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> d(N + 2, 0);
    for (int i = 0; i < N; ++i) {
        int a;
        scanf("%d", &a);
        if (a >= 0 && a <= N) {
            d[a] = 1;
        }
    }
    for (int i = 1; i < N + 2; ++i) {
        if (d[i] == 0) {
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}