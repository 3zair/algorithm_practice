#include <stdarg.h>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int> initVector(int count, ...) {
    vector<int> a;
    va_list args;
    va_start(args, count);
    while (count--) {
        a.push_back(va_arg(args, int));
    }
    va_end(args);

    return a;
}

queue<vector<int>> bads;

bool check(int i, int min, int max) { return i >= min && i <= max; }

bool findBads(int i, int j, vector<vector<int>>& grid) {
    bool flag = false;
    int maxJ = grid[0].size() - 1;
    int maxI = grid.size() - 1;
    printf("maxI:%d maxJ:%d\n", maxI, maxJ);

    if (check(i - 1, 0, maxI)) {
        printf("%d maxI:%d\n", i - 1, maxI);
        if (grid[i - 1][j] == 1) {
            printf("x:%d y:%d\n", i - 1, j);
            flag = true;
            bads.push(initVector(2, i - 1, j));
        }
    }

    if (check(i + 1, 0, maxI)) {
        if (grid[i + 1][j] == 1) {
            flag = true;
            bads.push(initVector(2, i + 1, j));
        }
    }

    if (check(j - 1, 0, maxJ)) {
        if (grid[i][j - 1] == 1) {
            flag = true;
            bads.push(initVector(2, i, j - 1));
        }
    }

    if (check(j + 1, 0, maxJ)) {
        if (grid[i][j + 1] == 1) {
            flag = true;
            bads.push(initVector(2, i, j + 1));
        }
    }

    return flag;
}

int orangesRotting(vector<vector<int>>& grid) {
    int m = 0;
    int row = grid.size();
    int col = grid[0].size();

    while (true) {
        m++;
        bool flag = false;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 2) {
                    if (findBads(i, j, grid)) {
                        flag = true;
                    }
                }
            }
        }

        while (bads.empty() == false) {
            vector<int> bad = bads.front();
            bads.pop();
            grid[bad[0]][bad[1]] = 2;
        }

        if (!flag) {
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (grid[i][j] == 1) {
                        return -1;
                    }
                }
            }
            return m - 1;
        }
    }
}

int main() {
    vector<vector<int>> grid;
    grid.push_back(initVector(1, 1));
    grid.push_back(initVector(1, 2));
    grid.push_back(initVector(1, 2));
    printf("%d\n", orangesRotting(grid));
}