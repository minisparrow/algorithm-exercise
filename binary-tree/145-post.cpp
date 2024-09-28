#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<int> res;
  vector<int> postorderTraversal(TreeNode *root) {
    // 1
    //   2
    // 3
    if (!root)
      return {};
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    res.push_back(root->val);
    return res;
  }
  vector<int> postorderTraversalWithStack(TreeNode *root) {
    //        5
    //       󰁂 󰁃
    //      4   6
    //     󰁂 󰁃
    //    1   2
    //   󰁂 󰁃
    // null null
    // 后序遍历：  左右中
    // 前序遍历：  中左右 -> 中右左 -> reverse -> 左右中
    //
    if (!root)
      return {};
    stack<TreeNode *> stk;
    vector<int> res{};
    stk.push(root);
    TreeNode *curr = root;
    while (!stk.empty()) {
      auto top = stk.top();
      stk.pop();
      res.push_back(top->val); // middle
      if (top->left)
        stk.push(top->left); // left
      if (top->right)
        stk.push(top->right); // right
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *t0 = new TreeNode(1);
  TreeNode *t1 = new TreeNode(2);
  TreeNode *t2 = new TreeNode(3);
  t0->right = t1;
  t1->left = t2;
  Solution *sln = new Solution;
  vector<int> res = sln->postorderTraversalWithStack(t0);
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
