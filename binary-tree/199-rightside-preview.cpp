
#include "tree-utils.h"
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    if (!root)
      return {};
    queue<TreeNode *> que;
    que.push(root);
    vector<int> res;
    while (!que.empty()) {
      int size = que.size();
      for (size_t i = 0; i < size; i++) {
        auto front = que.front();
        que.pop();
        if (i == size - 1)
          res.push_back(front->val);

        if (front->left)
          que.push(front->left);
        if (front->right)
          que.push(front->right);
      }
    }
    return res;
  }
  void print(vector<int> res) {
    cout << "[";
    for (size_t j = 0; j < res.size(); j++) {
      cout << res[j] << ",";
    }
    cout << "]" << endl;
  }
};

int main(int argc, char *argv[]) {
  //        1
  //       󰁂 󰁃
  //      2   3
  //       󰁃   󰁃
  //       5    4
  TreeNode *t0 = new TreeNode(1);
  TreeNode *t1 = new TreeNode(2);
  TreeNode *t2 = new TreeNode(3);
  TreeNode *t3 = new TreeNode(5);
  TreeNode *t4 = new TreeNode(4);
  t0->left = t1;
  t0->right = t2;
  t1->right = t3;
  t2->right = t4;
  PreviewTreeNode(t0, "tree.dot");
  Solution *sln = new Solution;
  vector<int> res = sln->rightSideView(t0);
  sln->print(res);

  return 0;
}
