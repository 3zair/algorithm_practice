#include <stdarg.h>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> initVector(int count, ...) {
    vector<int> a;
    va_list args;
    va_start(args, count);
    while (count--) {
        a.push_back(va_arg(args, int));
    }
    va_end(args);

    return a;
}
bool canThreePartsEqualSum(vector<int>& A) {
    int l = A.size();
    int sum = 0;
    for (int i = 0; i < l; ++i) {
        sum += A[i];
        // sum %= 3;
    }
    if (sum % 3 != 0) {
        printf("logA\n");
        return false;
    }
    int count = 0;
    int newSum = 0;
    for (int i = 0; i < l; ++i) {
        newSum += A[i];
        if (newSum == sum / 3) {
            newSum = 0;
            if (count == 1 && i != l - 1) {
                return true;
            }
            count++;
        }
    }

    printf("logB %d\n", count);
    return false;
}

int main() {
    vector<int> a = initVector(11, 0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1);
    printf("%d\n", canThreePartsEqualSum(a));
}