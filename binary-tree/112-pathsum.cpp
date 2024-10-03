
#include "tree-utils.h"
#include <queue>
#include <stack>
class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root)
      return false;
    queue<std::pair<TreeNode *, int>> que; // treenode, sum
    que.push(std::make_pair(root, root->val));
    int front_val;
    while (!que.empty()) {
      auto front = que.front();
      que.pop();
      auto front_node = front.first;
      front_val = front.second;

      if (!front_node->left && !front_node->right && front_val == targetSum)
        return true;

      if (front_node->left)
        que.push({front_node->left, front_val + front_node->left->val});
      if (front_node->right)
        que.push({front_node->right, front_val + front_node->right->val});
    }

    return false;
  }

  bool hasPathSumWithStack(TreeNode *root, int targetSum) {
    if (!root)
      return false;
    stack<std::pair<TreeNode *, int>> stk; // treenode, sum
    stk.push(std::make_pair(root, root->val));
    int val;
    while (!stk.empty()) {
      auto top = stk.top();
      stk.pop();
      auto node = top.first;
      val = top.second;

      if (!node->left && !node->right && val == targetSum) // root
        return true;

      if (node->right)
        stk.push({node->right, val + node->right->val}); // right
      if (node->left)
        stk.push({node->left, val + node->left->val}); // left
      // stk:  [root, right, left ->|
      // pop :  left, right
    }
    return false;
  }
};
int main(int argc, char *argv[]) {
  vector<int> arr{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1};
  TreeNode *tree = buildTreeFromVector<int>(arr);
  PreviewTreeNode(tree, "tree.dot");
  Solution *sln = new Solution;
  // cout << sln->hasPathSum(tree, 22) << endl;
  cout << sln->hasPathSumWithStack(tree, 22) << endl;
  return 0;
}
