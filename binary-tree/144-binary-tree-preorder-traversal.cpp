#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

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
  void helper(TreeNode* root, vector<int>& result) {
    //preorder
    if (root) {
      result.push_back(root->val);
      helper(root->left, result);
      helper(root->right, result);
    }
  }

  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    helper(root, result);
    return result;
  }

  vector<int> preorderTraversalWithStack(TreeNode* root) {
    if (!root) return {};
    vector<int> result;
    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty()) {
      TreeNode* topNode = stk.top();
      stk.pop();
      result.push_back(topNode->val);

      // stack first push right, and when pop, will pop last
      if (topNode->right) stk.push(topNode->right);
      if (topNode->left) stk.push(topNode->left);

    }
    return result;
  }
};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  node1->left = nullptr;
  node1->right = node2;

  node2->left = node3;
  node2->right = nullptr;

  Solution* sln = new Solution();
  vector<int> result;
  result = sln->preorderTraversalWithStack(node1);

  for(int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
