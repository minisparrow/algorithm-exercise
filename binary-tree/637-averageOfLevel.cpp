#include "tree-utils.h"
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> res;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      int size = que.size();

      double sum = 0;
      for (size_t i = 0; i < size; i++) {
        auto front = que.front();
        que.pop();
        sum += front->val;
        if (front->left)
          que.push(front->left);
        if (front->right)
          que.push(front->right);
      }
      res.push_back(sum / size);
    }
    return res;
  }
};

//        3
//       󰁂 󰁃
//      9   20
//          󰁂 󰁃
//         15  7
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
  vector<double> res;
  res = sln->averageOfLevels(t0);
  printVector(res);

  return 0;
}
