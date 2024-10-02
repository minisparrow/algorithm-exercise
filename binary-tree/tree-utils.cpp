#include "tree-utils.h"
void writeDot_old(TreeNode *root, std::ofstream &file) {
  if (root == nullptr)
    return;

  // 输出当前节点
  file << "    " << root->val << ";\n";

  // 递归输出左子树
  if (root->left) {
    file << "    " << root->val << " -> " << root->left->val << ";\n";
    writeDot_old(root->left, file);
  }

  // 递归输出右子树
  if (root->right) {
    file << "    " << root->val << " -> " << root->right->val << ";\n";
    writeDot_old(root->right, file);
  }
}

void writeDot(TreeNode *root, ofstream &file) {
  if (!root)
    return;

  file << "    \"" << root << "\" [label=\"" << root->val << "\"];\n";

  if (root->left) {
    file << "    \"" << root << "\" -> \"" << root->left << "\";\n";
    writeDot(root->left, file);
  }

  if (root->right) {
    file << "    \"" << root << "\" -> \"" << root->right << "\";\n";
    writeDot(root->right, file);
  }
}

void PreviewTreeNode(TreeNode *root, const std::string &filename) {
  std::ofstream file(filename);
  if (file.is_open()) {
    file << "digraph G {\n";
    writeDot(root, file);
    file << "}\n";
    file.close();
  } else {
    std::cerr << "Unable to open file";
  }
}

// template void printVector<double>(vector<double> &res);
// template void printVector<float>(vector<float> &res);
// template void printVector<int>(vector<int> &res);
