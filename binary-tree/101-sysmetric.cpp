#include "tree-utils.h"
#include <queue>
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    //        1
    //       󰁂 󰁃
    //      2    2
    //     󰁂 󰁃  󰁂 󰁃
    //    3  4  4  3
    //    =========================
    //    que: 2 2
    //    left: 2  right 2 ->
    //         ->  if left and right both null, continue
    //         ->  if !left | !right return false
    //         ->  if left->val != right->val return false
    //         ->  que.push(left->left)
    //         ->  que.push(right->right)
    //         ->  que.push(left->right)
    //         ->  que.push(right->left)
    //
    if (!root)
      return true;
    queue<TreeNode *> que;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
      auto leftnode = que.front();
      que.pop();
      auto rightnode = que.front();
      que.pop();

      if (!leftnode && !rightnode)
        continue;
      if (!leftnode || !rightnode)
        return false;
      if (leftnode->val != rightnode->val)
        return false;

      que.push(leftnode->left);
      que.push(rightnode->right);
      que.push(leftnode->right);
      que.push(rightnode->left);
    }
    return true;
  }
  bool isSymmetricDeprecate(TreeNode *root) {
    if (!root)
      return true;
    queue<TreeNode *> que;
    que.push(root);
    TreeNode *dummy = new TreeNode(-1);
    while (!que.empty()) {
      int size = que.size();
      vector<int> vec;
      for (size_t i = 0; i < size; i++) {
        auto front = que.front();
        que.pop();
        vec.push_back(front->val);

        if (front->left) {
          que.push(front->left);
        } else {
          que.push(dummy);
        }
        if (front->right)
          que.push(front->right);
        else
          que.push(dummy);
      }
      int left = 0, right = size - 1;
      while (left < right) {
        if (vec[left] == vec[right]) {
          left++;
          right--;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};

void test1() {
  TreeNode *t0 = new TreeNode(1);
  TreeNode *t1 = new TreeNode(2);
  TreeNode *t2 = new TreeNode(2);
  TreeNode *t3 = new TreeNode(3);
  TreeNode *t4 = new TreeNode(4);
  TreeNode *t5 = new TreeNode(4);
  TreeNode *t6 = new TreeNode(3);
  t0->left = t1;
  t0->right = t2;
  t1->left = t3;
  t1->right = t4;
  t2->left = t5;
  t2->right = t6;
  PreviewTreeNode(t0, "tree.dot");
  Solution *sln = new Solution;
  cout << sln->isSymmetric(t0) << endl;
}
void test2() {
  TreeNode *t0 = new TreeNode(1);
  TreeNode *t1 = new TreeNode(2);
  TreeNode *t2 = new TreeNode(2);
  TreeNode *t3 = new TreeNode(3);
  TreeNode *t4 = new TreeNode(3);
  t0->left = t1;
  t0->right = t2;
  t1->right = t3;
  t2->right = t4;
  PreviewTreeNode(t0, "tree.dot");
  Solution *sln = new Solution;
  cout << sln->isSymmetric(t0) << endl;
}
int main(int argc, char *argv[]) {
  test2();
  return 0;
}
