#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>

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
  vector<vector<int>> hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return {};
    queue<std::tuple<TreeNode*, int, vector<int>>> que;
    vector<vector<int>> ans;
    vector<int> temp;
    temp.push_back(root->val);
    que.emplace(root, root->val,temp);
    int val;
    TreeNode* frontNode;
    while (!que.empty()) {
      std::tie(frontNode, val, temp) = que.front();
      que.pop();
      if (frontNode->left == nullptr && frontNode->right == nullptr && val == targetSum) {
        cout << "sum:" << val << endl;
        ans.push_back(temp);
      };
      if (frontNode->left != nullptr) {
        vector<int> tempLeft;
        tempLeft = temp;
        tempLeft.emplace_back(frontNode->left->val);
        que.emplace(frontNode->left, val + frontNode->left->val, tempLeft);
      }
      if (frontNode->right != nullptr) {
        vector<int> tempRight;
        tempRight = temp;
        tempRight.emplace_back(frontNode->right->val);
        que.emplace(frontNode->right, val + frontNode->right->val, tempRight);
      }

    }
    return ans;
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
  TreeNode* node10 = new TreeNode(5);
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
  node6->left = node10;
  node6->right = node9;

  Solution* sln = new Solution();
  int targetSum = 22;
  vector<vector<int>> result;
  result = sln->hasPathSum(node1, targetSum);

  for(int i = 0; i < result.size(); ++i) {
    for(int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
