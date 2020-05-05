
#include <cstdio>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        int N;
        scanf("%d", &N);
        int lastN = -1, curN = -1, afterN = -1;
        int peaks = 0;
        for (int n = 0; n < N; ++n) {
            scanf("%d", &afterN);
            // printf("l%d, c:%d, a:%d\n", lastN, curN, afterN);
            if (lastN < curN && curN > afterN && lastN != -1 && curN != -1) {
                peaks++;
            }
            lastN = curN;
            curN = afterN;
        }

        printf("Case #%d: %d", t + 1, peaks);
        if (t != T - 1) {
            printf("\n");
        }
    }

    return 0;
}