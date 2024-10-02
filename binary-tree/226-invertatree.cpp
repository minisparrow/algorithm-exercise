
#include "tree-utils.h"
#include <queue>
#include <stack>
class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return root;
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      int size = que.size();
      for (size_t i = 0; i < size; i++) {
        auto front = que.front();
        que.pop();

        swap(front->left, front->right);

        if (front->left)
          que.push(front->left);
        if (front->right)
          que.push(front->right);
      }
    }

    return root;
  }

  // inorder
  TreeNode *invertTreeWithStack(TreeNode *root) {
    if (!root)
      return root;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
      auto top = stk.top();
      stk.pop();

      swap(top->left, top->right); // root
      if (top->right)              // right
        stk.push(top->right);
      if (top->left) // right
        stk.push(top->left);
    }

    return root;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *t0 = new TreeNode(4);
  TreeNode *t1 = new TreeNode(2);
  TreeNode *t2 = new TreeNode(7);
  TreeNode *t3 = new TreeNode(1);
  TreeNode *t4 = new TreeNode(3);
  TreeNode *t5 = new TreeNode(6);
  TreeNode *t6 = new TreeNode(9);
  t0->left = t1;
  t0->right = t2;
  t1->left = t3;
  t1->right = t4;
  t2->left = t5;
  t2->right = t6;
  PreviewTreeNode(t0, "tree.dot");
  Solution *sln = new Solution;
  // TreeNode *newtree_queue = sln->invertTree(t0);
  // PreviewTreeNode(newtree_queue, "tree_queue.dot");

  TreeNode *newtree_stack = sln->invertTreeWithStack(t0);
  PreviewTreeNode(newtree_stack, "tree_stack.dot");
  return 0;
}
