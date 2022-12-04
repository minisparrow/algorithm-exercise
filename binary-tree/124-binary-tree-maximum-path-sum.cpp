
#include <iostream>
#include <climits>
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
    int val = INT_MIN;
    int maxPathSum(TreeNode* root) {
         maxPathSumRecursive(root, val);
         return val;
    }

    int maxPathSumRecursive(TreeNode* root, int& val) {
        if (root == nullptr) return 0;
        int left = max(0,maxPathSumRecursive(root->left, val));
        int right = max(0,maxPathSumRecursive(root->right, val));
        int lmr = left + root->val + right;
        //int maxOfRoot = max(lmr, val);
        int ret = root->val + max(left, right);
        val = max(val, lmr);
        return ret;
    }
};


int main() {
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);
  n1->left = n2;
  n1->right = n3;

  Solution* sln = new Solution();
  int  result = sln->maxPathSum(n1);
  cout << result << endl;
  return 0;
}
