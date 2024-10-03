#include "tree-utils.h"
#include <stack>
#include <utility>

class Solution {
public:
  string vectorIntToString(vector<int> &vec) {
    //[1, 2, 3] -> "1->2-3"
    string s;
    for (size_t i = 0; i < vec.size(); i++) {
      s += std::to_string(vec[i]);
      if (i != vec.size() - 1)
        s += "->";
    }
    return s;
  }

  vector<string> binaryTreePaths(TreeNode *root) {
    // bread first search: queue
    queue<pair<TreeNode *, vector<int>>> que;
    vector<int> init{root->val};
    que.push(make_pair(root, init));
    vector<vector<int>> paths;
    while (!que.empty()) {
      auto front = que.front();
      auto node = front.first;
      auto val = front.second;
      que.pop();

      if (!node->left && !node->right)
        paths.push_back(val);

      if (node->left) {
        vector<int> templ{val};
        templ.push_back(node->left->val);
        que.push({node->left, templ});
      }
      if (node->right) {
        vector<int> tempr{val};
        tempr.push_back(node->right->val);
        que.push({node->right, tempr});
      }
    }
    // paths -> vector<vector<int>>
    vector<string> s;
    for (size_t i = 0; i < paths.size(); i++) {
      s.push_back(vectorIntToString(paths[i]));
    }
    return s;
  }
  vector<string> binaryTreePathsWithStack(TreeNode *root) {
    // dfs: preorder tranversal-> stack
    stack<pair<TreeNode *, vector<int>>> stk;
    vector<int> init{root->val};
    stk.push(make_pair(root, init));
    vector<vector<int>> paths;
    while (!stk.empty()) {
      auto top = stk.top();
      auto node = top.first;
      auto val = top.second;
      stk.pop();

      if (!node->left && !node->right)
        paths.push_back(val);

      if (node->right) {
        vector<int> tempr{val};
        tempr.push_back(node->right->val);
        stk.push({node->right, tempr});
      }
      if (node->left) {
        vector<int> templ{val};
        templ.push_back(node->left->val);
        stk.push({node->left, templ});
      }
    }
    // paths -> vector<vector<int>>
    vector<string> s;
    for (size_t i = 0; i < paths.size(); i++) {
      s.push_back(vectorIntToString(paths[i]));
    }
    return s;
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr{1, 2, 3, -1, 5};
  TreeNode *t = buildTreeFromVector(arr);
  PreviewTreeNode(t, "tree.dot");
  Solution *sln = new Solution;
  // vector<string> s = sln->binaryTreePaths(t);
  vector<string> s = sln->binaryTreePathsWithStack(t);
  for (size_t i = 0; i < s.size(); i++) {
    cout << s[i] << endl;
  }
  return 0;
}
