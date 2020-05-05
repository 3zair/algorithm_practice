#include <cstdio>
#include <vector>
using namespace std;

// 1
int findMin(vector<int> nums) {
    int l = nums.size();
    int y = 0;
    int min = nums[0];
    for (int i = 1; i < l; ++i) {
        if (min > nums[i]) {
            min = nums[i];
            y = i;
        }
    }

    return y;
}
vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int max = matrix[0][0];
    vector<int> retNums;
    int x = 0;
    for (int i = 0; i < matrix[0].size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            if (max < matrix[j][i]) {
                max = matrix[j][i];
                x = j;
            }
        }
        if (findMin(matrix[x]) == i) {
            retNums.emplace_back(matrix[x][i]);
        }
    }
    return retNums;
}

// 2
class CustomStack {
    int MaxSize;
    vector<int> S;

   public:
    CustomStack(int maxSize) { MaxSize = maxSize; }

    void push(int x) {
        if (S.size() < MaxSize) {
            S.emplace_back(x);
        }
    }

    int pop() {
        if (S.size() == 0) {
            return -1;
        }
        int ret = S[S.size() - 1];
        S.pop_back();
        return ret;
    }

    void increment(int k, int val) {
        int max = S.size() > k ? k : S.size();
        for (int i = 0; i < max; ++i) {
            printf("%d %d\n", i, S[i]);
            S[i] += val;
        }
    }
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 3
TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodeVal;
    TreeNode* node = root;
    while (node != NULL) {
        nodeVal.emplace_back(node->val);

    }
}

int main() {}