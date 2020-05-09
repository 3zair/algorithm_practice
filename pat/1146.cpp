#include <cstdio>
#include <map>
#include <vector>
using namespace std;

// 1146 Topological Order
// https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760
// 有向(无环)图拓扑排序
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int> > edges(m, vector<int>(2, 0));
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    int k = 0;
    scanf("%d", &k);
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
        map<int, int> order;
        for (int j = 0; j < n; ++j) {
            int a;
            scanf("%d", &a);
            order[a] = j;
        }
        for (int j = 0; j < m; ++j) {
            if (order[edges[j][0]] > order[edges[j][1]]) {
                ans.push_back(i);
                break;
            }
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        printf("%d%s", ans[i], i == ans.size() ? "" : " ");
    }
    return 0;
}