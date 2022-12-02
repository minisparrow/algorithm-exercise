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
  int minDepthBFS(TreeNode* root) {
    if (!root) return 0;
    queue<std::pair<TreeNode*, int>> que;
    //que.emplace(root, 1);
    que.push({root, 1});
    while (!que.empty()) {
      auto front = que.front();
      TreeNode* frontNode = front.first;
      int depth = front.second;
      que.pop();
      if (frontNode->left == nullptr && frontNode->right == nullptr) return depth;
      // if (frontNode->left != nullptr) que.emplace(frontNode->left, depth+1);
      // if (frontNode->right != nullptr) que.emplace(frontNode->right, depth+1);
      if (frontNode->left != nullptr) que.push({frontNode->left, depth+1});
      if (frontNode->right != nullptr) que.push({frontNode->right, depth+1});
    }
    return 0;
  }
  int minDepthRecursive(TreeNode* root) {
    if (!root) return 0;
    int mindepth = INT_MAX;
    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }
    if (root->left) {
       mindepth = min(mindepth, minDepthRecursive(root->left));
    }
    if (root->right) {
       mindepth = min(mindepth, minDepthRecursive(root->right));
    }

    return mindepth + 1;
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
  int resultRecursive = sln->minDepthRecursive(node1);
  int resultBFS = sln->minDepthBFS(node1);
  cout << "min depth of Recursive: "<< resultRecursive << endl;
  cout << "min depth of BFS: "<< resultBFS << endl;

  return 0;
}
