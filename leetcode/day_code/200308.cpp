#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    if (coins[0] > amount) {
        return -1;
    }
    int num = 0;
    if()
}