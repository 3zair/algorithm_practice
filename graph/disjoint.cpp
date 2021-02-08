#include <iostream>
#include <vector>
using namespace std;

int find_root(int x, vector<int> &parent) {
  int x_root = x;
  while (parent[x_root] != -1) {
    x_root = parent[x_root];
  }
  return x_root;
}

int union_vertices(int x, int y, vector<int> &parent) {
  int x_root = find_root(x, parent);
  int y_root = find_root(y, parent);
  if (x_root != y_root) {
    parent[x_root] = y_root;
    return 1;
  }

  return 0;
}

int main() {
  vector<int> p(6, -1);
  vector<vector<int>> edges;
  edges.push_back({0, 1});
  edges.push_back({1, 2});
  edges.push_back({1, 3});
  edges.push_back({3, 4});
  // edges.push_back({2,4});
  edges.push_back({2, 5});

  for (int i = 0; i < edges.size(); ++i) {
    int x = edges[i][0];
    int y = edges[i][1];
    if (union_vertices(x, y, p) == 0) {
      printf("Cycle detected! x:%d, y:%d\n", x, y);
      return 0;
    }
  }
  printf("No cycles founded!\n");

  return 0;
}