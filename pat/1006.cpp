/*
** 1006:Sign In and Sign Out
** https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928
*/

#include <string.h>
#include <iostream>
using namespace std;

bool compare(int a[], int b[]) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] < b[2];
    return a[2] < a[3];
}

void copyfromB(int a[], int b[]) {
    for (int i = 0; i < 3; i++) a[i] = b[i];
}

int main() {
    int m;
    int e[3] = {23, 59, 59};
    int l[3] = {0, 0, 0};
    int t1[3], t2[3];
    char lockID[16], unlockID[16], temp[16];

    scanf("%d", &m);
    //  printf("%d\n",m);
    for (int i = 0; i < m; i++) {
        scanf("%s %d:%d:%d %d:%d:%d", temp, &t1[0], &t1[1], &t1[2], &t2[0],
              &t2[1], &t2[2]);
        if (compare(t1, e)) {
            copyfromB(e, t1);
            strcpy(lockID, temp);
        }
        if (compare(l, t2)) {
            copyfromB(l, t2);
            strcpy(unlockID, temp);
        }
    }
    printf("%s %s\n", lockID, unlockID);
}