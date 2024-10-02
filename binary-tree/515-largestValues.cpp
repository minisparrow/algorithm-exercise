
#include "tree-utils.h"
#include <climits>
#include <queue>

class Solution {
public:
  vector<int> largestValues(TreeNode *root) {
    if (!root)
      return {};
    queue<TreeNode *> que;
    que.push(root);

    vector<int> res;
    while (!que.empty()) {
      int size = que.size();
      int maxV = INT_MIN;
      for (size_t i = 0; i < size; i++) {
        auto front = que.front();
        que.pop();
        int val = front->val;
        maxV = val > maxV ? val : maxV;

        if (front->left)
          que.push(front->left);
        if (front->right)
          que.push(front->right);
      }
      res.push_back(maxV);
    }

    return res;
  }
};

int main(int argc, char *argv[]) {
  //        1
  //       󰁂 󰁃
  //      3   2
  //     󰁂 󰁃    󰁃
  //    5   4    9
  TreeNode *t0 = new TreeNode(1);
  TreeNode *t1 = new TreeNode(3);
  TreeNode *t2 = new TreeNode(2);
  TreeNode *t3 = new TreeNode(5);
  TreeNode *t4 = new TreeNode(4);
  TreeNode *t5 = new TreeNode(9);
  t0->left = t1;
  t1->left = t3;
  t1->right = t4;
  t0->right = t2;
  t2->right = t5;
  PreviewTreeNode(t0, "tree.dot");
  Solution *sln = new Solution;
  vector<int> res = sln->largestValues(t0);
  printVector<int>(res);

  return 0;
}
