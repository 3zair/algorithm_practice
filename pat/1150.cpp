#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M;
    map<string, int> distArr;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int c1, c2, dist;
        scanf("%d %d %d", &c1, &c2, &dist);
        string key = to_string(c1) + to_string(c2);
        distArr[key] = dist;
    }

    int K;
    scanf("%d", &K);
    int cityNum = INT32_MAX;
    int shortPath = 0;
    int shortDist = INT32_MAX;
    for (int i = 0; i < K; ++i) {
        vector<int> vist(N, 0);
        int n;
        scanf("%d", &n);
        int lC, sum = 0;
        scanf("%d", &lC);
        int start = lC;
        vist[lC - 1] = 1;
        for (int j = 1; j < n; ++j) {
            int c, d;
            scanf("%d", &c);
            vist[c - 1] = 1;
            map<string, int>::iterator it;
            it = distArr.find(to_string(lC) + to_string(c));
            if (it == distArr.end()) {
                it = distArr.find(to_string(c) + to_string(lC));
                if (it == distArr.end()) {
                    sum = -1;
                    break;
                }
            }
            d = it->second;

            sum += d;
            lC = c;
        }
        bool vistedAll = true;
        for (int a = 0; a < N; ++a) {
            if (vist[a] == 0) {
                vistedAll = false;
            }
        }
        if (sum == -1) {
            printf("Path %d: NA(%s)\n", i + 1, "Not a TS cycle");
            continue;
        }
        string tail = "";
        if (start == lC && n == N + 1 && vistedAll) {
            tail = "TS simple cycle";
        } else if (start == lC && n > N + 1 && vistedAll) {
            tail = "TS cycle";
        } else {
            tail = "Not a TS cycle";
        }
        if (vistedAll) {
            if (sum < shortDist || (sum == shortDist && cityNum < n)) {
                shortDist = sum;
                shortPath = i + 1;
                cityNum = n;
            }
        }
        printf("Path %d: %d (%s)\n", i + 1, sum, tail.c_str());
    }
    if (shortDist != INT32_MAX) {
        printf("Shortest Dist(%d) = %d\n", shortPath, shortDist);
    }

    return 0;
}