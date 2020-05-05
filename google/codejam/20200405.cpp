#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        int N;
        scanf("%d", &N);
        vector<vector<int>> m(N, vector<int>(N, 0));
        int k = 0, r = 0, c = 0;
        for (int n = 0; n < N; ++n) {
            for (int j = 0; j < N; ++j) {
                int a;
                scanf("%d", &a);
                if (n == j) {
                    k += a;
                }
                m[n][a - 1] = m[n][a - 1] == 0 || m[n][a - 1] == 1 ? 1 : 2;
                m[a - 1][j] = m[a - 1][j] == 0 || m[a - 1][j] == -1 ? -1 : 2;
            }
        }

        for (int i = 0; i < N; ++i) {
            bool rflag = false;
            bool cflag = false;
            for (int j = 0; j < N; ++j) {
                if (m[i][j] != 1 && m[i][j] != 2) {
                    rflag = true;
                }
                if (m[j][i] != -1 && m[j][i] != 2) {
                    cflag = true;
                }
            }
            if (rflag) {
                r++;
            }
            if (cflag) {
                c++;
            }
        }
        if (t == T - 1) {
            printf("Case #%d: %d %d %d", t + 1, k, r, c);
            break;
        }
        printf("Case #%d: %d %d %d\n", t + 1, k, r, c);
    }
}