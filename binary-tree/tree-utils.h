#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// void writeDot(TreeNode *root, std::ofstream &file);
void PreviewTreeNode(TreeNode *root, const std::string &filename);

template <typename T> void printVector(vector<T> &res) {
  cout << "[";
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i] << ",";
  }
  cout << "]" << endl;
}

template <typename T> TreeNode *buildTreeFromVector(vector<T> &arr) {
  // arr:
  // 1, 2, 3, -1, -1, 4, 5
  // -->
  // tree:
  //      1
  //    2    3
  // -1  -1 4  5
  //
  if (arr.empty()) {
    return nullptr;
  }
  TreeNode *root = new TreeNode(arr[0]);
  queue<TreeNode *> que;
  que.push(root);
  int i = 1;
  while (i < arr.size()) {
    auto front = que.front();
    que.pop();
    if (arr[i] != -1) {
      front->left = new TreeNode(arr[i]);
      que.push(front->left);
    }
    i++; // i = 2
    if (arr[i] != -1) {
      front->right = new TreeNode(arr[i]);
      que.push(front->right);
    }
    i++;
  }

  return root;
}
