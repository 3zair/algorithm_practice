#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;
// w3-1 01
int largestAltitude(vector<int>& gain) {
  int ans = 0;
  int curAl = 0;
  for (int i = 0; i < gain.size(); ++i) {
    curAl += gain[i];
    if (ans < curAl) {
      ans = curAl;
    }
  }

  return ans;
}
// 02
int cmpABLan(int a, int b, vector<vector<int>>& languages) {
  set<int> tmp;
  for (auto x : languages[a]) tmp.insert(x);
  for (auto y : languages[b]) tmp.insert(y);

  return tmp.size();
}
int visited[500][500];
vector<vector<int>> edges;
set<int> badFriends;

int minimumTeachings(int n, vector<vector<int>>& languages,
                     vector<vector<int>>& friendships) {
  edges.resize(n);
  for (int i = 0; i < languages.size(); ++i) {
    if (cmpABLan(friendships[i][0], friendships[i][1], languages) !=
        languages[friendships[i][1]].size() +
            languages[friendships[i][1]].size()) {
      badFriends.insert(friendships[i][0]);
      edges[friendships[i][0]].push_back(friendships[i][1]);
      badFriends.insert(friendships[i][1]);
      edges[friendships[i][1]].push_back(friendships[i][0]);
    }
  }
  for (int i = 1; i < 501; ++i)
    for (int j = 1; j < 501; ++j) visited[i][j] = 0;
  int ans = 0;
  for (auto a : badFriends) {
    int sz = 0;
    set<int> tmp;
    for (auto x : edges[a]) {
      if (visited[x][a] == 0) {
        sz += languages[x].size();
        for (auto xLan : languages[a]) tmp.insert(xLan);
        visited[x][a] = 1;
        visited[a][x] = 1;
      }
    }
    ans += sz - tmp.size() > edges[a].size() ? 1 : sz - tmp.size();
  }

  return ans;
}

//周赛
string maximumTime(string time) {
  if (time[0] == '?' && time[1] == '?') {
    time[0] = '2';
    time[1] = '3';
  }
  if (time[0] == '?') time[0] = time[1] < '4' ? '2' : '1';
  if (time[1] == '?') time[1] = time[0] == '2' ? '3' : '9';
  if (time[3] == '?') time[3] = '5';
  if (time[4] == '?') time[4] = '9';

  return time;
}

int minCharacters(string a, string b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans11 = 0, ans12 = 0, ans21 = 0, ans22 = 0, ans3 = 0;
  int szA = a.size();
  int szB = b.size();
  for (int i = 0; i < szB; ++i) {
    if (b[i] <= a[szA - 1]) {
      ans11++;
    }
  }
  for (int i = szA - 1; i >= 0; i--) {
    if (a[i] > b[0]) {
      ans12++;
    }
  }

  for (int i = 0; i < szA; ++i) {
    if (a[i] <= b[szB - 1]) {
      ans21++;
    }
  }
  for (int i = szB - 1; i >= 0; i--) {
    if (b[i] > a[0]) {
      ans22++;
    }
  }
  int ans1 = min(ans11, ans12);
  int ans2 = min(ans21, ans22);

  int ans = 0;
  map<char, int> count;
  for (auto aa : a) {
    count[aa]++;
    if (ans < count[aa]) ans = count[aa];
  }
  for (auto bb : b) {
    count[bb]++;
    if (ans < count[bb]) ans = count[bb];
  }
  int ans3 = szA + szB - ans;
  int ans12 = min(ans1, ans2);
  printf("%d %d %d\n", ans1, ans2, ans3);
  return min(ans3, ans12);
}

class Solution22401 {
 public:
  map<int, int> sums;
  map<int, int> count;

  int sum(int x) {
    int _x = x, ans = 0;
    while (x != 0) {
      if (sums[x] != 0) {
        sums[_x] = sums[x] + ans;
        return sums[x];
      }
      ans += x % 10;
      x = x / 10;
    }

    sums[_x] = ans;
    return ans;
  }
  int countBalls(int lowLimit, int highLimit) {
    int ans = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
      count[sums[i]]++;
    }
    map<int, int>::iterator it = count.begin();
    while (it != count.end()) {
      if (ans < it->second) {
        ans = it->second;
      }
    }

    return ans;
  }
};
class Solution22402 {
 public:
  map<int, int> count;
  map<int, int> conn;

  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    for (int i = 0; i < adjacentPairs.size(); i++) {
      count[adjacentPairs[i][0]]++;
      count[adjacentPairs[i][1]]++;
      conn[adjacentPairs[i][0]] = adjacentPairs[i][1];
      conn[adjacentPairs[i][1]] = adjacentPairs[i][0];
    }
    auto it = count.begin();
    int start = 0;
    while (it != count.end()) {
      if (it->second == 1) {
        start = it->first;
        break;
      }
    }

    vector<int> ans;
    ans.push_back(start);
  }
};

class Solution {
 public:
  int sum(vector<int> A) {
    int sum = 0;
    for (auto a : A) {
      sum += a;
    }

    return sum;
  }

  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);
    int tmp = (sumA - sumB) / 2;
    unordered_set<int> tmpB(B.begin(), B.end());
    vector<int> ans;
    for (auto a : A) {
      int b = a - tmp;
      if (tmpB.count(b)) {
        ans.push_back(a);
        ans.push_back(b);
        return ans;
      }
      // for (auto b : B) {
      //   if (a - b == tmp) {
      //     ans.push_back(a);
      //     ans.push_back(b);
      //     return ans;
      //   }
    }

    return ans;
  }
};

class Solution0202 {
 public:
  int characterReplacement(string s, int k) {
    int len = s.size();
    if (len < 2) return len;
    int l = 0, r = 0;
    int ans = 0;
    vector<char> count(26, 0);
    int maxC;
    while (r < len) {
      count[s[r]]++;
      maxC = maxC < count[s[r]] ? count[s[r]] : maxC;
      r++;
      if (r - l < maxC + k) {
        count[s[l]]--;
        l++;
      }
    }
    return r - l;
  }
};

class Solution0204 {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    if (nums.size() == 1) return nums[0];

    double sumK = accumulate(nums.begin(), nums.begin() + k - 1, 0.00);
    double ans = sumK / k;

    int i = 1, j = k;
    while (j < nums.size()) {
      sumK -= nums[i - 1];
      sumK += nums[j];
      double tmp = sumK / k;
      if (ans < tmp) ans = tmp;
      i++;
      j++;
    }

    return ans;
  }
};

int main() {}
