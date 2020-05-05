
#include <stdarg.h>
#include <cstdio>
#include <string>
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
// 1
string generateTheString(int n) {
    vector<string> A = {"a", "b"};
    string ret;
    for (int i = 0; i < n - 1; ++i) {
        ret += A[0];
    }
    if (n % 2 == 0) {
        ret += A[1];
    } else {
        ret += A[0];
    }
    return ret;
}

// 2
int numTimesAllBlue(vector<int>& light) {
    int n = light.size();
    int head = 0;
    int count = 0;
    int tail = 0;
    vector<int> Lights(n, 1);
    for (int i = 0; i < n; ++i) {
        if (tail < light[i] - 1) {
            tail = light[i] - 1;
        }
        // printf("m%d\n", i);
        // for (int j = 0; j < n; ++j) {
        //     printf("%d", Lights[j]);
        // }
        // printf("\n");

        if (head + 1 == light[i]) {
            Lights[head] = 2;
            for (int j = head; j < n; ++j) {
                if (Lights[j] == 1) {
                    head = j;
                    // printf("head:%d tail:%d light[i]:%d i:%d\n", head, tail,
                    //        light[i], i);
                    if (head - 1 == tail) {
                        count++;
                    }
                    break;
                }
                if (j == n - 1) {
                    count++;
                }
            }
        } else {
            Lights[light[i] - 1] = 2;
        }
    }
    printf("count:%d head:%d\n", count, head);
    return count;
}
int main() {
    vector<int> a = initVector(5, 2, 1, 3, 5, 4);
    numTimesAllBlue(a);
}