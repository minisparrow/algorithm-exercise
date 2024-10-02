
#include "tree-utils.h"

int main(int argc, char *argv[]) {
  vector<int> arr{1, 2, 3, -1, -1, 2, 5};
  TreeNode *t = buildTreeFromVector<int>(arr);
  PreviewTreeNode(t, "demo.dot");
  return 0;
}
