#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    int lsum = 0;
    vector<int> ret;
    for (int i = 0; i < nums.size(); ++i) {
        lsum += nums[i];
        ret.emplace_back(nums[i]);
        if (lsum > sum - lsum) {
            break;
        }
    }
    return ret;
}
// 2
string add(string s) {
    for (int i = s.size(); i >= 0; --i) {
        if (s[i] == '0') {
            s[i] = '1';
            return s;
        }
        s[i] = '0';
    }
    s = "1" + s;

    return s;
}

int numSteps(string s) {
    int count = 0;
    while (s.size() != 1) {
        if (s[s.size() - 1] == '0') {
            s.pop_back();
            count++;
            continue;
        }
        s = add(s);
        count++;
    }

    return count;
}
// 3
string longestDiverseString(int a, int b, int c) {
    map<int, string> chars;
    chars[a] = "a";
    chars[b] = "b";
    chars[c] = "c";
    vector<int> q = {a, b, c};
    sort(q.begin(), q.end());
    for (int i = 0; i < 3; ++i) {
        chars[i] = chars[q[i]];
    }
    while (q[2]!=0||q[1]) {
        
    }
}