#include <cstdio>
#include <vector>
using namespace std;

// -1：活变死 2：死变活
void gameOfLife(vector<vector<int>>& board) {
    int xs[] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int ys[] = {-1, 0, 1, -1, 0, 1, -1, 1};
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            int count = 0;
            for (int k = 0; k < 8; ++k) {
                int cx = i + xs[k];
                int cy = j + ys[k];
                if (cx < board.size() && cy < board[0].size() && cx >= 0 &&
                    cy >= 0) {
                    if (board[cx][cy] == 1 || board[cx][cy] == -1) {
                        count++;
                    }
                }
            }
            if (board[i][j] == 1) {
                if (count < 2 || count > 3) {
                    board[i][j] = -1;
                }
            }
            if (board[i][j] == 0 && count == 3) {
                board[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == 2) {
                board[i][j] = 1;
            }
            if (board[i][j] == -1) {
                board[i][j] = 0;
            }
        }
    }

    return;
}


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {0, 1, -1};

        int rows = board.size();
        int cols = board[0].size();

        // 创建复制数组 copyBoard
        vector<vector<int> >copyBoard(rows, vector<int>(cols, 0));

        // 从原数组复制一份到 copyBoard 中
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                copyBoard[row][col] = board[row][col];
            }
        }

        // 遍历面板每一个格子里的细胞
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // 对于每一个细胞统计其八个相邻位置里的活细胞数量
                int liveNeighbors = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {

                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);

                            // 查看相邻的细胞是否是活细胞
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (copyBoard[r][c] == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }

                // 规则 1 或规则 3      
                if ((copyBoard[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = 0;
                }
                // 规则 4
                if (copyBoard[row][col] == 0 && liveNeighbors == 3) {
                    board[row][col] = 1;
                }
            }
        }
    }
};
int main(int argc, char const* argv[]) {
    /* code */
    return 0;
}
