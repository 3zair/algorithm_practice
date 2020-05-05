// #include <cstdio>
// using namespace std;

// bool check() {

// }

// bool cmp(int a, int radixA, int b, int radixB) {

// }

// int main() {
//     int N1, N2, tag, radix;
//     scanf("%d %d %d %d", &N1, &N2, &tag, &radix);
// }

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
struct bign {
    int len;
    int d[30];
    bign() {
        len = 0;
        memset(d, 0, sizeof(d));
    }
};

bign change(char str[], int &q) {
    q = 1;
    bign a;
    a.len = strlen(str);
    for (int i = a.len - 1; i >= 0; --i) {
        if (isdigit(str[i])) {
            a.d[a.len - 1 - i] = str[i] - '0';

        } else {
            a.d[a.len - 1 - i] = str[i] - 'a' + 10;
        }
        q = q > a.d[a.len - 1 - i] ? q : a.d[a.len - 1 - i];
    }
    ++q;
    return a;
}

LL transform(bign a, int r) {
    LL ans = 0, p = 1;
    for (int i = 0; i < a.len; ++i) {
        ans += a.d[i] * p;
        p *= r;
    }
    return ans;
}
int binary_search(LL low, LL high, LL answer, bign a) {
    while (low <= high) {
        LL mid = (low + high) / 2;
        LL res = transform(a, mid);
        if (res == answer)
            return mid;
        else if (res > answer || res < 0)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n, tag, radix, r1, r2;
    char a[20], b[20];
    scanf("%s %s %d %d", a, b, &tag, &radix);
    bign a1 = change(a, r1);
    bign b1 = change(b, r2);
    int ans;
    if (tag == 1) {
        LL x = transform(a1, radix);
        LL l = r2;
        LL h = max(x, (LL)r2);
        ans = binary_search(l, h, x, b1);
    } else {
        LL x = transform(b1, radix);
        LL l = r1;
        LL h = max(x, (LL)r1);
        ans = binary_search(l, h, x, a1);
    }
    if (ans == -1)
        printf("Impossible\n");
    else
        printf("%d\n", ans);
    return 0;
}