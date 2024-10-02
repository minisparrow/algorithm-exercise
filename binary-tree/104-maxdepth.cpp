#include "tree-utils.h"
#include <queue>
using namespace std;
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    queue<TreeNode *> que;
    que.push(root);
    int depth = 0;
    while (!que.empty()) {
      int size = que.size();
      depth += 1;
      for (size_t i = 0; i < size; i++) {
        auto front = que.front();
        que.pop();

        if (front->left)
          que.push(front->left);
        if (front->right)
          que.push(front->right);
      }
    }

    return depth;
  }
};

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
  int depth = sln->maxDepth(t0);
  cout << depth << endl;
  return 0;
}
