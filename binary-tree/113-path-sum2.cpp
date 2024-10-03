

#include "tree-utils.h"
#include <numeric>
#include <queue>
#include <stack>
class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (!root)
      return {};
    queue<std::pair<TreeNode *, vector<int>>> que; // treenode, path

    vector<int> init{root->val};
    vector<vector<int>> paths;
    que.push(std::make_pair(root, init));
    while (!que.empty()) {
      vector<int> path;
      auto front = que.front();
      que.pop();
      auto front_node = front.first;
      path = front.second;
      int sumOfPath = accumulate(path.begin(), path.end(), 0);

      if (!front_node->left && !front_node->right && sumOfPath == targetSum)
        paths.push_back(path);

      if (front_node->left) {
        vector<int> templ{path};
        templ.push_back(front_node->left->val);
        que.push({front_node->left, templ});
      }
      if (front_node->right) {
        vector<int> tempr{path};
        tempr.push_back(front_node->right->val);
        que.push({front_node->right, tempr});
      }
    }
    return paths;
  }

  vector<vector<int>> pathSumWithStack(TreeNode *root, int targetSum) {
    if (!root)
      return {};
    stack<std::pair<TreeNode *, vector<int>>> stk; // treenode,path
    vector<int> init{root->val};
    stk.push(std::make_pair(root, init));
    int val;
    vector<vector<int>> paths;
    while (!stk.empty()) {
      vector<int> path;
      auto top = stk.top();
      stk.pop();
      auto node = top.first;
      path = top.second;
      int sumOfPath = accumulate(path.begin(), path.end(), 0);

      if (!node->left && !node->right && sumOfPath == targetSum) // root
        paths.push_back(path);

      if (node->right) {
        vector<int> tempr{path};
        tempr.push_back(node->right->val);
        stk.push({node->right, tempr}); // right
      }
      if (node->left) {
        vector<int> templ{path};
        templ.push_back(node->left->val);
        stk.push({node->left, templ}); // left
      }
    }
    return paths;
  }
};
int main(int argc, char *argv[]) {
  vector<int> arr{5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
  TreeNode *tree = buildTreeFromVector<int>(arr);
  PreviewTreeNode(tree, "tree.dot");
  Solution *sln = new Solution;
  // vector<vector<int>> res = sln->pathSum(tree, 22);

  vector<vector<int>> res = sln->pathSumWithStack(tree, 22);
  cout << res.size() << endl;
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
