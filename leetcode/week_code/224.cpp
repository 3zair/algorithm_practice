//
// Created by 张子钊 on 2021/1/17.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// 01
int countGoodRectangles(vector<vector<int>>& rectangles) {
  map<int, int> count;
  for (int i = 0; i < rectangles.size(); ++i) {
    int maxLen = 1000000000;
    if (maxLen > rectangles[i][0]) {
      maxLen = rectangles[i][0];
    }
    if (maxLen > rectangles[i][1]) {
      maxLen = rectangles[i][1];
    }
    count[maxLen]++;
  }

  int maxCount = 0, max = 0;
  map<int, int>::iterator iter = count.begin();
  while (iter != count.end()) {
    if (max < iter->first) {
      maxCount = iter->second;
      max = iter->first;
    }
    iter++;
  }
  return maxCount;
}
// 02
int tupleSameProduct(vector<int>& nums) {
  int results[10001][10001];
  for (int i = 0; i < 10001; i++) {
    for (int j = 0; j < 10001; j++) {
      results[i][j] = 0;
    }
  }

  int sz = nums.size();
  int ans = 0;
  for (int i = 0; i < sz; ++i) {
    int a = nums[i];
    for (int j = i + 1; j < sz; ++j) {
      int b = nums[j];
      if (results[a][b] == 0) {
        results[a][b] = a * b;
        results[b][a] = results[a][b];
      }

      for (int x = 0; x < sz; ++x) {
        int c = nums[x];
        if (a == c || b == c) continue;
        // if (ab % c != 0) continue;
        // int d = ab / c;
        for (int y = x + 1; y < sz; ++y) {
          int d = nums[y];
          if (results[c][d] == 0) {
            results[c][d] = c * d;
            results[d][c] = results[c][d];
          }
          if (results[a][b] == results[c][d]) {
            ans++;
          }
        }
      }
    }
  }
  return ans * 4;
}
int main() {
  vector<int> nums = {1, 2, 4, 5, 10};
  printf("%d\n", tupleSameProduct(nums));
}