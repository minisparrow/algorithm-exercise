
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
  vector<int> preorderTraversal(TreeNode *root) {
    // 1
    //   2
    // 3
    if (!root)
      return {};
    res.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    return res;
  }

  vector<int> preorderTraversalWithStack(TreeNode *root) {
    // 1
    //  󰁃
    //   2
    // 󰁂
    // 3
    // 1. 节点访问， 节点处理
    // middle, left, right
    //
    //
    // op: init         | s: 1  | res: {}
    // op: pop          | s:    | res: {1}
    // op: push right   | s: 2, | res: {1}
    // op: push left    | s: 2, | res: {1}
    //
    // op: pop          | s:    | res: {1, 2}
    // op: push right   | s:    | res: {1, 2}
    // op: push left    | s: 3  | res: {1, 2}
    //
    // op: pop          | s:    | res: {1, 2, 3}
    // op: push right   | s:    | res: {1, 2, 3}
    // op: push left    | s:    | res: {1, 2, 3}
    // s is empty, stop
    //
    stack<TreeNode *> stk;
    vector<int> res;
    stk.push(root);
    while (!stk.empty()) {
      auto top = stk.top();
      stk.pop();
      res.push_back(top->val); // 中
      if (top->right)
        stk.push(top->right); // 右
      if (top->left)
        stk.push(top->left); // 左
    }
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
  // vector<int> res = sln->preorderTraversal(t0);
  vector<int> res = sln->preorderTraversalWithStack(t0);
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
