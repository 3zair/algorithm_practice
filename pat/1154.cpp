#include <cstdio>
#include <set>
#include <vector>

using namespace std;

// 1154 Vertex Coloring
// https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552
// 经典看起来很复杂实则比较简单的题
int main() {
    int N, M;
    scanf("%d %d\n", &N, &M);
    // 建议改为vector<node>
    // struct node { int a,b}
    vector<vector<int> > edges(M, vector<int>(2, 0));
    for (int m = 0; m < M; ++m) {
        scanf("%d %d", &edges[m][0], &edges[m][1]);
    }
    int K;
    scanf("%d", &K);

    for (int k = 0; k < K; ++k) {
        // 建议改为int[10009] 数组
        vector<int> verticesColor(N);
        set<int> colorAll;
        for (int n = 0; n < N; ++n) {
            int c;
            scanf("%d", &c);
            colorAll.insert(c);
            verticesColor[n] = c;
        }
        bool flag = true;
        for (int i = 0; i < M; ++i) {
            if (verticesColor[edges[i][0]] == verticesColor[edges[i][1]]) {
                flag = false;
                break;
            }
        }
        if (!flag)
            printf("No\n");
        else {
            int num = colorAll.size();
            printf("%d-coloring\n", num);
        }
    }

    return 0;
}