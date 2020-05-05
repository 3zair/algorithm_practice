#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct node {
    string key;
    int value;
};

bool cmp(node &a, node &b) {
    return a.value != b.value ? a.value > b.value : a.key < b.key;
}

// 1153 Decode Registration Card of PAT
// https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928
int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    vector<node> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i].key >> data[i].value;
    }
    for (int i = 0; i < m; ++i) {
        int t;
        string s;
        vector<node> ans;
        cin >> t >> s;
        printf("Case %d: %d %s\n", i + 1, t, s.c_str());
        if (t == 1) {
            for (int j = 0; j < n; ++j) {
                if (data[j].key[0] == s[0]) ans.push_back(data[j]);
            }
        } else if (t == 2) {
            int count = 0, sum = 0;
            for (int j = 0; j < n; ++j) {
                if (data[j].key.substr(1, 3) == s) {
                    count++;
                    sum += data[j].value;
                }
            }
            if (count != 0) {
                printf("%d %d\n", count, sum);
            } else {
                printf("NA\n");
            }
            continue;
        } else if (t == 3) {
            unordered_map<string, int> um;
            for (int j = 0; j < n; j++)
                if (data[j].key.substr(4, 6) == s)
                    um[data[j].key.substr(1, 3)]++;
            for (auto it : um) ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end(), cmp);
        if (ans.size() == 0) {
            printf("NA\n");
        } else {
            for (int k = 0; k < ans.size(); ++k) {
                printf("%s %d\n", ans[k].key.c_str(), ans[k].value);
            }
        }
    }
    return 0;
}