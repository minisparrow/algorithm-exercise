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
    if (root) {
      helper(root->left, result);
      result.push_back(root->val);
      helper(root->right, result);
    }
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    helper(root, result);
    return result;
  }



 vector<int> inorderTraversalWithStack(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> stk;

    // 模拟计算机递归压栈的过程
    while(root || !stk.empty()) {
        //left
        while(root) {
            stk.push(root);
            root = root->left;
        }
        //middle
        root = stk.top();
        stk.pop();
        result.push_back(root->val);

        //right
        root = root->right;
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
  result = sln->inorderTraversalWithStack(node1);

  for(int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
