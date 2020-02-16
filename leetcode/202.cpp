#include <iostream>
#include <vector>
using namespace std;

int work(int a) {
    int sum = 0;
    int mod;
    while (a != 0) {
        mod = a % 10;
        sum += mod * mod;
        a /= 10;
    }

    return sum;
}
bool findNum(vector<int> nums, int n) {
    vector<int>::iterator ret;
    ret = find(nums.begin(), nums.end(), n);

    return ret != nums.end();
}

bool isHappy(int n) {
    vector<int> nums;
    while (n != 1) {
        n = work(n);
        if (findNum(nums, n)) return false;

        nums.push_back(n);
    }

    return true;
}
int main() { printf("result: %d\n", isHappy(18)); }
