#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

// 1149 Dangerous Goods Packaging
// https://pintia.cn/problem-sets/994805342720868352/problems/1038429908921778176
int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    map<int, vector<int> > incompatibleGoods;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        incompatibleGoods[a].push_back(b);
    }
    for (int i = 0; i < m; ++i) {
        int k;
        scanf("%d", &k);
        vector<int> list(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &list[j]);
        }
        bool flag = true;
        for (int j = 0; j < k; ++j) {
            if (incompatibleGoods.find(list[j]) != incompatibleGoods.end()) {
                for (int a = 0; a < incompatibleGoods[list[j]].size(); ++a) {
                    if (find(list.begin(), list.end(),
                             incompatibleGoods[list[j]][a]) != list.end()) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        printf("%s\n", flag ? "Yes" : "No");
    }

    return 0;
}