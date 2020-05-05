#include <cstdio>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// https://leetcode-cn.com/problems/diameter-of-binary-tree/

int ans = 1;
int depth(TreeNode *node) {
    if (node == NULL) {
        return 0;
    }
    int L = depth(node->left);
    int R = depth(node->right);
    if ((L + R + 1) > ans) {
        ans = L + R + 1;
    }
    int max = L > R ? L : R;

    return max + 1;
}
int diameterOfBinaryTree(TreeNode *root) {
    depth(root);
    return ans - 1;
}

int main() {
    TreeNode root = TreeNode(1);
    TreeNode n1 = TreeNode(2);
    TreeNode n2 = TreeNode(3);
    root.left = &n1;
    root.right = &n2;
    TreeNode n3 = TreeNode(4);
    TreeNode n4 = TreeNode(5);
    n1.left = &n3;
    n1.right = &n4;
    TreeNode n5 = TreeNode(1);
    TreeNode n6 = TreeNode(1);

    printf("%d\n", diameterOfBinaryTree(&root));
}