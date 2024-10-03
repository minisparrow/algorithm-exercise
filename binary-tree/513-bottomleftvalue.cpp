#include "tree-utils.h"
class Solution {
public:
  int findBottomLeftValue(TreeNode *root) {
    int res = root->val;
    queue<TreeNode *> que; // node, isFirstValue, isLeft
    que.push({root});
    while (!que.empty()) {
      int size = que.size();
      for (size_t i = 0; i < size; i++) {
        auto front = que.front();
        que.pop();
        auto node = front;
        if (!node->left && !node->right && i == 0)
          res = node->val;
        if (node->left)
          que.push({node->left});
        if (node->right)
          que.push({node->right});
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr{1, 2, 3, 4, -1, 5, 6, -1, -1, 7};
  // vector<int> arr{1, 2, 3};
  TreeNode *t = buildTreeFromVector(arr);
  Solution *sln = new Solution;
  int res = sln->findBottomLeftValue(t);
  cout << res << endl;
  return 0;
}
