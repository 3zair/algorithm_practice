#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

// 1140 Look-and-say Sequence
// https://pintia.cn/problem-sets/994805342720868352/problems/994805344490864640
int main() {
    int d, n;
    scanf("%d %d", &d, &n);
    vector<int> s;
    s.push_back(d);
    int k = 1;
    while (k < n) {
        vector<int> sTmp;
        vector<int> sTmpN;
        sTmp.push_back(s[0]);
        sTmpN.push_back(0);
        for (int i = 0; i < s.size(); ++i) {
            if (sTmp[sTmp.size() - 1] == s[i]) {
                sTmpN[sTmpN.size() - 1]++;
            } else {
                sTmp.push_back(s[i]);
                sTmpN.push_back(1);
            }
        }
        // for (int i = 0; i < s.size(); ++i) printf("%d ", s[i]);
        // printf("\n");
        // for (int i = 0; i < sTmp.size(); ++i) printf("%d ", sTmp[i]);
        // printf("\n");
        // for (int i = 0; i < sTmpN.size(); ++i) printf("%d ", sTmpN[i]);
        // printf("\n");
        s.clear();
        for (int i = 0; i < sTmp.size(); ++i) {
            s.push_back(sTmp[i]);
            s.push_back(sTmpN[i]);
        }
        k++;
    }

    for (int i = 0; i < s.size(); ++i) printf("%d", s[i]);

    return 0;
}