#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int> nodes(1000);
vector<int> ks;
int n = 0;
bool isMin = true, isMax = true;

void walk(int k) {
    if (k > n) return;
    ks.push_back(k);
    if (k * 2 > n && (k * 2 + 1) > n) {
        for (int i = 0; i < ks.size(); ++i) {
            printf("%d%c", nodes[ks[i]], i < ks.size() - 1 ? ' ' : '\n');
        }
    }

    if ((k * 2 + 1) <= n) {
        if (nodes[k] < nodes[k * 2 + 1]) {
            isMax = false;
        } else if (nodes[k] > nodes[k * 2 + 1]) {
            isMin = false;
        }
        walk(k * 2 + 1);
    }

    if (k * 2 <= n) {
        if (nodes[k] < nodes[k * 2]) {
            isMax = false;
        } else if (nodes[k] > nodes[k * 2]) {
            isMin = false;
        }
        walk(k * 2);
    }

    ks.pop_back();
}

// 1155 Heap Paths
//  https://pintia.cn/problem-sets/994805342720868352/problems/1071785408849047552
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &nodes[i]);
    }
    n = N;

    walk(1);
    if (isMax == true)
        printf("Max Heap\n");
    else if (isMin == true)
        printf("Min Heap\n");
    else
        printf("Not Heap\n");
    return 0;
}