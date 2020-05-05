#include <cstdio>
#include <vector>
using namespace std;
int get(int n, int m, int r, int c) {
    vector<int> heads;
    heads.emplace_back(1);
    for (int k = 1; n - (k - 1) * 2 > 0; ++k) {
        int end = heads[heads.size() - 1];
        heads.emplace_back(end + ((n - (k - 1) * 2 + m - k * 2) * 2));
    }
    int k = r;
    if (r > n / 2) {
        k = n - r;
    }
    int ret = 0;
    if (k == r) {
        printf("%d %d\n", k, heads[k - 1]);
        ret = heads[k - 1] + c - k;
    }
    if (k == n - r) {
        ret = heads[k - 1] + 2 * (m - k * 2) - (c - k);
    }
    if (k == m - c) {
        ret = heads[k - 1] + (m - k * 2) + (r - k);
    }

    if (k == c && k != r) {
        ret = heads[k - 1] + (n - (k - 1) * 2 + m - k * 2) * 2 - (r - k);
    }

    for (int i = 0; i < heads.size(); ++i) {
        printf("%d ", heads[i]);
    }

    printf("\n%d\n", ret);

    return ret;
}
int main() { get(4, 5, 2, 2); }