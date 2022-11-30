#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

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
  vector<int> stackTemplate(TreeNode* root) {
    if (!root) return {};
    vector<int> result;

    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()) {
      TreeNode* front = que.front();
      que.pop();
      result.push_back(front->val);
      if(front->left) que.push(front->left);
      if(front->right) que.push(front->right);
    }
    return result;
  }


  vector<vector<int>> levelOrderBottomWithStack(TreeNode* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<TreeNode*> que;

    que.push(root);

    while(!que.empty()) {

      int queSize = que.size();
      vector<int> temp;

      for(int i = 0; i < queSize; i++) {
        TreeNode* front = que.front();
        que.pop();
        temp.push_back(front->val);
        if(front->left) que.push(front->left);
        if(front->right) que.push(front->right);
        if (i == queSize - 1) {
          result.push_back(temp);
        }
      }
    }

    reverse(result.begin(), result.end());

    return result;
  }


};

int main() {
  TreeNode* node1 = new TreeNode(3);
  TreeNode* node2 = new TreeNode(9);
  TreeNode* node3 = new TreeNode(20);
  TreeNode* node4 = new TreeNode(15);
  TreeNode* node5 = new TreeNode(7);

  node1->left = node2;
  node1->right = node3;

  node3->left = node4;
  node3->right = node5;

  Solution* sln = new Solution();
  vector<vector<int>> result;
  // result = sln->levelOrder(node1);
  result = sln->levelOrderBottomWithStack(node1);

  vector<int> resultFlatten;
  resultFlatten = sln->stackTemplate(node1);

  for(int i = 0; i < result.size(); ++i) {
    for(int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
  }
  cout << endl;



  cout << "stack flatten: \n";
  for(int j = 0; j < resultFlatten.size(); ++j) {
    cout << resultFlatten[j] << " ";
  }
  cout << endl;

  return 0;
}
