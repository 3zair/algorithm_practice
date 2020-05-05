#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string destCity(vector<vector<string> >& paths) {
    vector<string> starts;
    vector<string> ends;
    for (int i = 0; i < paths.size(); ++i) {
        starts.emplace_back(paths[i][0]);
        ends.emplace_back(paths[i][1]);
    }
    for (int i = 0; i < ends.size(); ++i) {
        if (find(starts.begin(), starts.end(), ends[i]) != starts.end()) {
            return ends[i];
        }
    }
    return "";
}

bool kLengthApart(vector<int>& nums, int k) {
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            count++;
        } else {
            if (count < k && i != 0) {
                return false;
            }
            count = 0;
        }
    }
    return count >= k;
}

int absoluteDiff(int a, int b) {
    if (a > b) {
        return a - b;
    }
    return b - a;
}

int longestSubarray(vector<int>& nums, int limit) {
    vector<int> spaces;
    int maxLen = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = nums.size(); j >= i; --j) {
            vector<int> a(nums.begin() + i, nums.begin() + j);
            if (maxLen > a.size()) {
                break;
            }
            sort(a.begin(), a.end());
            if ((a.begin() - (a.end() - 1)) <= limit) {
                maxLen = maxLen < a.size() ? a.size() : maxLen;
            }
        }
    }
    return maxLen;
}
int main() {}