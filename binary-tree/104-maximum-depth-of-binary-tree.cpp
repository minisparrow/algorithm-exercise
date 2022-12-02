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
  int maxDepthBFS(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> que;
    que.emplace(root);
    int maxdepth = 0;
    while (!que.empty()) {
      int queSize = que.size();
      for  (int i = 0; i < queSize; i++) {
        TreeNode* frontNode = que.front();
        que.pop();
        if (frontNode->left != nullptr) que.emplace(frontNode->left);
        if (frontNode->right != nullptr) que.emplace(frontNode->right);
      }
      maxdepth += 1;
    }
    return maxdepth;
  }
  int maxDepthRecursive(TreeNode* root) {
    if (!root) return 0;
    int maxdepth = INT_MIN;
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    if (root->left) {
       maxdepth= max(maxdepth, maxDepthRecursive(root->left));
    }
    if (root->right) {
       maxdepth= max(maxdepth, maxDepthRecursive(root->right));
    }

    return maxdepth + 1;
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
  int resultRecursive = sln->maxDepthRecursive(node1);
  int resultBFS = sln->maxDepthBFS(node1);
  cout << "max depth of Recursive: "<< resultRecursive << endl;
  cout << "max depth of BFS: "<< resultBFS << endl;

  return 0;
}
