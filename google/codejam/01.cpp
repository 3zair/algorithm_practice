#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ac {
    int s;
    int e;
};

bool cmp(ac x, ac y) {
    if (x.s < y.s) return 1;
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int n;
        scanf("%d", &n);
        char id[n];
        ac tl[n];
        ac oTl[n];
        for (int j = 0; j < n; ++j) {
            int a, b;
            scanf("%d%d", &a, &b);
            tl[j].s = a;
            tl[j].e = b;
            oTl[j].s = a;
            oTl[j].e = b;
        }
        int aC = 0, aJ = 1;
        sort(tl, tl + n, cmp);
        ac cT;
        cT.s = tl[0].s;
        cT.e = tl[0].e;
        ac jT;
        for (int j = 0; j < n; ++j) {
            if (tl[0].s == oTl[j].s && tl[0].e == oTl[j].e) id[j] = 'C';
        }
        bool flag = false;
        for (int j = 1; j < n; ++j) {
            flag = false;
            if (!aC) {
                if (tl[j].s >= cT.e) {
                    aC = 1;
                }
            }
            if (!aJ) {
                if (tl[j].s >= jT.e) {
                    aJ = 1;
                }
            }
            if (aC) {
                cT.s = tl[j].s;
                cT.e = tl[j].e;
                flag = true;
                aC = 0;
                for (int g = 0; g < n; ++g) {
                    if (tl[j].s == oTl[g].s && tl[j].e == oTl[g].e) {
                        id[g] = 'C';
                        break;
                    }
                }
            }
            if (aJ && !flag) {
                jT.s = tl[j].s;
                jT.e = tl[j].e;
                flag = true;
                aJ = 0;
                for (int g = 0; g < n; ++g) {
                    if (tl[j].s == oTl[g].s && tl[j].e == oTl[g].e) {
                        id[g] = 'J';
                        break;
                    }
                }
            }
            if (!flag) break;
        }
        if (!flag) {
            cout << "Case #" << i << ": IMPOSSIBLE";
        } else {
            printf("Case #%d: %s", i, id);
        }
        if (i != t) cout << endl;
    }
    return 0;
}