#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

// https://leetcode-cn.com/problems/majority-element/
// 题解里面投票法很有意思
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

int main() {}