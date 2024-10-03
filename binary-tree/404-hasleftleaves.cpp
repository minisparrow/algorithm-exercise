#include "tree-utils.h"

class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root)
      return 0;
    queue<std::pair<TreeNode *, bool>> que;
    que.push({root, false});
    int sum = 0;
    while (!que.empty()) {
      auto front = que.front();
      que.pop();
      auto node = front.first;
      auto isLeft = front.second;

      if (!node->left && !node->right && isLeft)
        sum += node->val;

      if (node->left)
        que.push({node->left, true});
      if (node->right)
        que.push({node->right, false});
    }
    return sum;
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr{3, 9, 20, -1, -1, 15, 7};
  TreeNode *t = buildTreeFromVector(arr);
  PreviewTreeNode(t, "tree.dot");
  Solution *sln = new Solution;
  cout << sln->sumOfLeftLeaves(t) << endl;
  return 0;
}
