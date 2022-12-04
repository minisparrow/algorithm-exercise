#include <iostream>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) {
            return root; 
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q); 
        TreeNode* right = lowestCommonAncestor(root->right, p, q); 
        if (left != NULL && right != NULL) {
            return root; 
        }
        else if (left == NULL) return right; 
        else return left; 
    }
};

int main() {
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(1);
    node1->left = node2;
    node1->right = node3;

    Solution* sln = new Solution();
    TreeNode *lca = sln->lowestCommonAncestor(node1, node2, node3);
    cout << lca->val << endl;
    return 0;
}
