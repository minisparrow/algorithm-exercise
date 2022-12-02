#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
//#include <map>
#include <climits>

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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    queue<std::pair<TreeNode*, int>> que;
    que.push({root, root->val});
    int val;
    while (!que.empty()) {
      auto front = que.front();
      TreeNode* frontNode = front.first;
      val = front.second;
      que.pop();
      if (frontNode->left == nullptr && frontNode->right == nullptr && val == targetSum) {
        cout << "sum:" << val << endl;
        return true;
      };
      if (frontNode->left != nullptr) que.push({frontNode->left, val + frontNode->left->val});
      if (frontNode->right != nullptr) que.push({frontNode->right, val + frontNode->right->val});
    }
    cout << "sum False:" << val << endl;
    return false;
  }
};

int main() {
  TreeNode* node1 = new TreeNode(5);
  TreeNode* node2 = new TreeNode(4);
  TreeNode* node3 = new TreeNode(8);
  TreeNode* node4 = new TreeNode(11);
  TreeNode* node5 = new TreeNode(13);
  TreeNode* node6 = new TreeNode(4);
  TreeNode* node7 = new TreeNode(7);
  TreeNode* node8 = new TreeNode(2);
  TreeNode* node9 = new TreeNode(1);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = nullptr;
  node3->left = node5;
  node3->right = node6;
  node4->left = node7;
  node4->right = node8;
  node5->left = nullptr;
  node5->right = nullptr;
  node6->left = nullptr;
  node6->right = node9;

  Solution* sln = new Solution();
  int targetSum = 22;
  bool result = sln->hasPathSum(node1, targetSum);
  cout << "hasPathSum  "<< result << endl;

  return 0;
}
