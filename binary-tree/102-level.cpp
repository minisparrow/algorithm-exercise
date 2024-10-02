#include "tree-utils.h"
#include <iostream>
#include <queue>
using namespace std;
// Definition for a binary tree node.

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    // breadfirst tranversal 广度优先遍历（遍历）
    vector<vector<int>> res;
    if (!root)
      return {};
    //        3
    //       󰁂 󰁃
    //      9   20
    //          󰁂 󰁃
    //         15  7
    //=============================
    // init | q: 3
    // pop  | inner: {3}  res : {3}
    // push | que: 9, 20
    // pop  | inner {9, 20}, res : {3}, {9, 20}
    // push | 9 child, 20 child -> que: {15, 7}
    // pop  | inner {15, 7}, res : {3}, {9, 20}, {15,7}
    //=============================
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      int size = que.size();
      vector<int> inner;
      // current level queue pop
      for (int i = 0; i < size; i++) {
        auto front = que.front();
        que.pop();
        inner.push_back(front->val);

        // next level queue push
        if (front->left)
          que.push(front->left);
        if (front->right)
          que.push(front->right);
      }
      res.push_back(inner);
    }
    return res;
  }
  void print(vector<vector<int>> res) {
    cout << "[";
    for (int i = 0; i < res.size(); ++i) {
      vector<int> inner = res[i];
      cout << "[";
      for (size_t j = 0; j < inner.size(); j++) {
        cout << inner[j] << ",";
      }
      cout << "]";
    }
    cout << "]" << endl;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *t0 = new TreeNode(3);
  TreeNode *t1 = new TreeNode(9);
  TreeNode *t2 = new TreeNode(20);
  TreeNode *t3 = new TreeNode(15);
  TreeNode *t4 = new TreeNode(7);
  t0->left = t1;
  t0->right = t2;
  t2->left = t3;
  t2->right = t4;
  PreviewTreeNode(t0, "tree.dot");
  Solution *sln = new Solution;
  vector<vector<int>> res = sln->levelOrder(t0);
  sln->print(res);

  return 0;
}
