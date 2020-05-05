#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> ret;
    int mid = (target + 1) / 2;
    for (int i = 1; i < mid; ++i) {
        int sum = 0;
        vector<int> r;
        for (int j = i; j < target; ++j) {
            sum += j;
            r.emplace_back(j);
            if (sum > target) {
                break;
            } else if (sum == target) {
                ret.emplace_back(r);
            }
        }
    }

    return ret;
}
int main() { return 0; }