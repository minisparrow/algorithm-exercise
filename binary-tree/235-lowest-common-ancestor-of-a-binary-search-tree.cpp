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
        while(root != NULL) {
            if (root->val < min(p->val, q->val)) {
                root = root->right;
            } else if (root->val > max(p->val, q->val)) {
                root = root->left;
            }
            else {
                break;
            }
        }
        return root;
    }
};

int main() {
    TreeNode* node1 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(9);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node7;
    node3->right = node9;

    Solution* sln = new Solution();
    TreeNode *lca = sln->lowestCommonAncestor(node1, node2, node3);
    cout << lca->val << endl;
    return 0;
}
