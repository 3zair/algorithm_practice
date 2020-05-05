#include <cstdio>
using namespace std;

// https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
struct Node {
    Node *Point;
    int Value;
};
struct MyQueue {
    int max;
    int l;
    Node *head;
    Node *tail;
};

class MaxQueue {
    MyQueue q;

   public:
    MaxQueue() {
        Node *n;
        n = new Node;
        q.max = -1;
        q.l = 0;
        q.head = n;
    }

    int max_value() { return q.max; }

    void push_back(int value) {
        Node *Newnode;
        Newnode = new Node;
        Newnode->Value = value;
        Newnode->Point = NULL;

        if (q.l > 0) {
            q.tail->Point = Newnode;
        } else {
            q.head->Point = Newnode;
        }
        q.tail = Newnode;

        q.l += 1;

        if (value > q.max) {
            q.max = value;
        }
    }

    int pop_front() {
        if (q.l <= 0) {
            return -1;
        }
        Node *retNode = q.head->Point;
        int ret = retNode->Value;
        // delete retNode;
        q.head->Point = q.head->Point->Point;
        q.l -= 1;
        if (q.max == ret) {
            q.max = -1;
            Node *node = q.head->Point;
            while (node != NULL) {
                // printf("%d\n", node->Value);
                if (q.max <= node->Value) {
                    q.max = node->Value;
                }
                node = node->Point;
            }
        }
        return ret;
    }
};

int main() {
    MaxQueue q = MaxQueue();
    q.push_back(2);
    q.push_back(1);
    printf("%d\n", q.max_value());
    printf("%d\n", q.pop_front());
    printf("%d\n", q.max_value());
}