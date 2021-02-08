#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 0117
// 比价好的思路 y1/x1 = y2/x2 => x1*y2 = x2*y1
bool checkStraightLine(vector<vector<int>>& coordinates) {
  if (coordinates.size() == 2) return true;
  if (coordinates[1][0] - coordinates[0][0] == 0) {
    for (int i = 1; i < coordinates.size() - 1; i++) {
      if (coordinates[i + 1][0] - coordinates[i][0] != 0) {
        return false;
      }
    }
    return true;
  }

  int k = (coordinates[1][1] - coordinates[0][1]) /
          (coordinates[1][0] - coordinates[0][0]);
  int m = (coordinates[1][1] - coordinates[0][1]) %
          (coordinates[1][0] - coordinates[0][0]);
  for (int i = 1; i < coordinates.size() - 1; i++) {
    if ((coordinates[i + 1][0] - coordinates[i][0]) == 0) return false;
    if (k != (coordinates[i + 1][1] - coordinates[i][1]) /
                 (coordinates[i + 1][0] - coordinates[i][0])) {
      return false;
    }

    if (m != (coordinates[i + 1][1] - coordinates[i][1]) %
                 (coordinates[i + 1][0] - coordinates[i][0])) {
      return false;
    }
  }

  return true;
}

// 0120
// 三个最大正数或者两个最小负数*一个最大正数
int maximumProduct(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size();
  return max(nums[0] * nums[1] * nums[n - 1],
             nums[n - 3] * nums[n - 2] * nums[n - 1]);
}
// 0122
vector<int> addToArrayForm(vector<int>& A, int K) {
  vector<int> KA;
  int k = K;
  while (k != 0) {
    KA.emplace_back(k % 10);
    k = k / 10;
  }
  int n = KA.size() > A.size() ? KA.size() : A.size();
  int An = A.size();
  vector<int> tmp;
  int flag = 0;  // 进位
  for (int i = 0; i < n; i++) {
    int a = 0;
    if (i >= KA.size())
      a = A[An - i - 1] + flag;
    else if (An - i - 1 < 0)
      a = KA[i] + flag;
    else
      a = KA[i] + A[An - i - 1] + flag;

    if (a > 9) {
      a = a % 10;
      flag = 1;
    } else
      flag = 0;

    tmp.push_back(a);
  }
  if (flag == 1) tmp.push_back(flag);
  vector<int> ans;
  for (int i = tmp.size() - 1; i >= 0; i--) {
    ans.push_back(tmp[i]);
  }
  // for (auto a:ans) {
  //     printf("%d ", a);
  // }
  return ans;
}
// 0124
vector<vector<int>> edges;
vector<bool> visited;
void dfs(int a) {
  visited[a] = true;
  for (auto x : edges[a]) {
    if (!visited[x]) {
      dfs(x);
    }
  }

  return;
}
int makeConnected(int n, vector<vector<int>>& connections) {
  if (connections.size() < n - 1) return -1;

  visited.resize(n);
  for (auto c : connections) {
    edges[c[0]].push_back(c[1]);
    edges[c[1]].push_back(c[0]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
      ans++;
    }
  }

  return ans++;
}
// 0124
int findLengthOfLCIS(vector<int>& nums) {
  int ans = 0;
  int count = 1;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i - 1] < nums[i]) {
      count++;
    } else {
      if (ans < count) ans = count;
      count = 1;
    }
  }

  return ans;
}
// 0125
class Solution0125 {
 public:
  int find(int a, vector<int> par) {
    if (par[a] == a) return a;

    int root = find(par[a], par);
    par[a] = root;

    return root;
  }
  void merge(int a, int b, vector<int> par) {
    int root_a = find(a, par);
    int root_b = find(b, par);
    par[root_b] = root_a;

    return;
  }
  int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();

    // init parents
    int N = n * n * 4;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) p[i] = i;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int id = i * n + j;
        int id2 = id * 4;
        if (i < n - 1) {
          int bottom_id = id + n;
          merge(id * 4 + 2, bottom_id * 4, p);
        }
        if (j < n - 1) {
          int right_id = id + 1;
          merge(id * 4 + 1, right_id * 4 + 3, p);
        }
        if (grid[i][j] == '/') {
          merge(id2, id2 + 3, p);
          merge(id2 + 1, id2 + 2, p);
        } else if (grid[i][j] == '\\') {
          merge(id2 + 1, id2, p);
          merge(id2 + 2, id2 + 3, p);
        } else {
          merge(id2 + 1, id2, p);
          merge(id2 + 1, id2 + 2, p);
          merge(id2 + 2, id2 + 3, p);
        }
      }
    }
    unordered_set<int> parents;
    for (int i = 0; i < N; ++i) {
      int parent = find(i, p);
      parents.insert(parent);
    }
    int ans = parents.size();
    printf("%d\n", ans);
    return parents.size();
  }
};

// 0126
int numEquivDominoPairs(vector<vector<int>>& dominoes) {
  int ans = 0;
  for (int i = 0; i < dominoes.size(); ++i) {
    for (int j = i + 1; i < dominoes.size(); ++j) {
      if ((dominoes[i][0] == dominoes[j][0] &&
           dominoes[i][1] == dominoes[j][1]) ||
          (dominoes[i][1] == dominoes[j][0] &&
           dominoes[i][1] == dominoes[j][0]))
        ans++;
    }
  }

  return ans;
}
class Solution0128 {
 public:
  int pivotIndex(vector<int>& nums) {
    if (nums.size() == 0) return -1;
    if (nums.size() == 1) return 0;
    if (nums.size() == 2) {
      if (nums[1] == 0) return 0;
      if (nums[0] == 0) return 1;
      return -1;
    }

    int l = 0, r = nums[1], ans = 0;
    for (int j = 2; j < nums.size(); j++) r += nums[j];

    while (l != r) {
      l += nums[ans];
      r -= nums[ans + 1];
      ans++;
      if (ans > nums.size() - 1) return -1;
    }

    return ans;
  }
};

// 0129
// 并查集

class Solution0129 {
 public:
  vector<int> parents;
  vector<int> len;
  void init_union(int n) {
    for (int i = 0; i < n; i++) {
      parents.push_back(-1);
      len.push_back(1);
    }
  }
  bool edgeCmp(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<2>(a) < get<2>(a);
  }

  int find(int x) {
    if (parents[x] == x) return x;

    parents[x] = findset(parents[x]);

    return parents[x];
  }

  bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return false;
    }
    if (len[x] < len[y]) {
      swap(x, y);
    }
    parents[y] = x;
    len[x] += len[y];

    return true;
  }
  bool connected(int x, int y) {
    x = find(x);
    y = find(y);
    return x == y;
  }

  int minimumEffortPath(vector<vector<int>>& heights) {
    int col = heights[0].size();
    int row = heights.size();
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        int id = i * row + j;
        if (i > 0) {
          edges.emplace_back(id - row, id,
                             abs(heights[i][j] - heights[i - 1][j]));
        }
        if (j > 0) {
          edges.emplace_back(id - 1, id,
                             abs(heights[i][j] - heights[i][j - 1]));
        }
      }
    }

    sort(edges.begin(), edges.end(), edgeCmp);
    init_union(col * row);
    int ans = 0;
    for (const auto [x, y, v] : edges) {
      merge(x, y);
      if (connected(0, row * col - 1)) {
        ans = v;
        break;
      }
    }
    return ans;
  }
};

class Solution0130 {
 public:
  int n = 0;
  int check(int x, int y) { return x < n && x >= 0 && y < n && y >= 0; }
  int dfs(int x, int y, int t, vector<vector<bool>>& visited,
          vector<vector<int>>& grid) {
    if (x == n - 1 && y == n - 1) return true;
    visited[x][y] = true;
    if (check(x - 1, y) && !visited[x - 1][y] && grid[x - 1][y] <= t)
      return dfs(x - 1, y, t, visited, grid);
    if (check(x + 1, y) && !visited[x + 1][y], grid[x + 1][y] <= t)
      return dfs(x + 1, y, t, visited, grid);
    if (check(x, y + 1) && !visited[x][y + 1], grid[x][y + 1] <= t)
      return dfs(x, y + 1, t, visited, grid);
    if (check(x, y - 1) && !visited[x][y - 1], grid[x][y - 1] <= t)
      return dfs(x, y - 1, t, visited, grid);

    return false;
  }
  int swimInWater(vector<vector<int>>& grid) {
    int ans = 0;
    n = grid.size();
    int l = 0, r = n * n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      vector<vector<bool>> visited;
      vector<bool> tmp;
      for (int i = 0; i < n; i++) tmp.emplace_back(false);
      for (int i = 0; i < n; i++) visited.emplace_back(tmp);
      if (dfs(0, 0, mid, visited, grid)) {
        ans = mid;
        r = mid;
      } else
        l = mid;
    }

    return ans;
  }
};

int main() {
  // vector<int> parent(6, -1);
  vector<string> edges;
  edges.push_back(" /");
  edges.push_back("/ ");
  Solution0125 S;
  S.regionsBySlashes(edges);
}