#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

struct Node {
    int Value;
    int LChild;
    int RChild;
};

Node tree[101];
int datas[101];

int p = 0;
int set(int node) {
    if (node == -1) {
        return 0;
    }
    if (tree[node].LChild != -1) {
        set(tree[node].LChild);
    }
    tree[node].Value = datas[p];
    p++;
    if (tree[node].RChild != -1) {
        set(tree[node].RChild);
    }
    return 0;
}

int LevelOrderTraverse(int root, int N) {
    if (root == -1) {
        return 0;
    }
    queue<Node> q;
    q.push(tree[root]);
    int n = 0;
    Node node;
    while (q.size()) {
        node = q.front();
        q.pop();
        n++;
        if (n < N) {
            printf("%d ", node.Value);
        } else {
            printf("%d", node.Value);
        }

        if (node.LChild != -1) {
            q.push(tree[node.LChild]);
        }
        if (node.RChild != -1) {
            q.push(tree[node.RChild]);
        }
    }

    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &tree[i].LChild, &tree[i].RChild);
    }

    for (int i = 0; i < N; ++i) {
        scanf("%d", &datas[i]);
    }
    sort(datas, datas + N);
    set(0);
    LevelOrderTraverse(0, N);
}