#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;

    scanf("%d", &N);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    vector<int> IDS(N, 1);
    for (int i = 0; i < N; ++i) {
        IDS[i] = -1;
        for (int j = i + 1; j < N; ++j) {
            IDS[j] = -1;
            int lCount = 0;
            int wLcount = 0;
            for (int k = 0; k < N; ++k) {
                int v = A[k];
                if (v > 0) {
                    if (IDS[v - 1] != 1) {
                        if (k == i || k == j) {
                            wLcount++;
                        }
                        lCount++;
                    }
                } else {
                    if (IDS[v * -1 - 1] != -1) {
                        if (k == i || k == j) {
                            wLcount++;
                        }
                        lCount++;
                    }
                }
            }
            if (lCount == 2 && wLcount == 1) {
                printf("%d %d", i + 1, j + 1);
                return 0;
            }
            IDS[j] = 1;
        }
        IDS[i] = 1;
    }

    printf("No Solution");
    return 0;
}