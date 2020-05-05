#include <math.h>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> target;
    for (int i = 0; i < nums.size(); ++i) {
        target.insert(target.begin() + index[i], nums[i]);
    }
    return target;
}

// 2
int SumN(int n) {
    int sum = 1 + n;
    if (n == 0 || n == 1) {
        return 0;
    }
    int count = 2;
    int max = sqrt(n);
    for (int i = 2; i <= max; ++i) {
        if (n % i == 0) {
            if (n / i == i) {
                count++;
            } else {
                count += 2;
            }
            if (count > 4) {
                return 0;
            }
            sum += i + n / i;
        }
    }
    sum = count == 4 ? sum : 0;
    return sum;
}
int sumFourDivisors(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += SumN(nums[i]);
    }

    return sum;
}

// 3

map<int, vector<int>> passMap;
bool check(int a, int next) {
    for (int i = 0; i < passMap[a].size(); ++i) {
        if (next == passMap[a][i]) {
            return true;
        }
    }
}
bool walk(int x, int y, vector<vector<int>>& grid) {
    if (x == grid.size() - 1 && y == grid[0].size()) {
        return true;
    }
    if (grid[x][y] == 1 && y + 1 < grid[0].size()) {
        if (check(grid[x][y], grid[x][y + 1])) {
            return walk(x, y + 1, grid);
        } else {
            return false;
        }
    }
    if ((grid[x][y] == 2 || grid[x][y] == 3 || grid[x][y] == 4) &&
        x + 1 < grid[0].size()) {
        if (check(grid[x][y], grid[x][y + 1])) {
            return walk(x+1, y, grid);
        } else {
            return false;
        }
    }
    if ((grid[x][y] == 5 || grid[x][y] == 6) && y - 1 > 0) {
        if (check(grid[x][y], grid[x-1][y])) {
            return walk(x-1, y, grid);
        } else {
            return false;
        }
    }
    if ((grid[x][y] == 5 || grid[x][y] == 6) && y - 1 > 0) {
        if (check(grid[x][y], grid[x][y-1])) {
            return walk(x, y-1, grid);
        } else {
            return false;
        }
    }

    return false;
}

bool hasValidPath(vector<vector<int>>& grid) {
    passMap[1] = {1, 3, 5};
    passMap[2] = {2, 5, 6};
    passMap[3] = {3, 5, 6};
    passMap[4] = {2, 5, 6};
    passMap[5] = {2, 3, 4};
    passMap[6] = {2, 3, 4};
    return walk(0, 0, grid);
}

int main() {}