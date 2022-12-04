#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <deque>
#include <string>
#include <list>

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
  void helper(TreeNode* root, string& result) {
    //preorder
    if (root) {
      result += to_string(root->val) + ',';
      helper(root->left, result);
      helper(root->right, result);
    } else
      result += "Null,";

  }

  string serialize(TreeNode* root) {
    string result;
    helper(root, result);
    return result;
  }

  string serializeWithStack(TreeNode* root) {
    if (!root) return {};
    string result;
    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty()) {
      TreeNode* topNode = stk.top();
      stk.pop();
      if (topNode != nullptr) {
         result += to_string(topNode->val) + ",";

         // stack first push right, and when pop, will pop last
         if (topNode->right)
           stk.push(topNode->right);
         else stk.push(nullptr);

         if (topNode->left)
            stk.push(topNode->left);
         else stk.push(nullptr);
      } else {
         result += "null,";
      }


    }
    return result;
  }

   // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        stringstream ss(data);
        list<string> l;

        string tmp;
        while (getline(ss, tmp, ',')) {
            l.push_back(tmp);
        }

        return deserializeDFS(l);
    }

    TreeNode* deserializeDFS(list<string> &l) {
        if (l.front() == "null") {
            l.pop_front();
            return nullptr;
        }
        //TreeNode* root = new TreeNode(std::stoi(l.front()));
        int s = std::stoi(l.front());
        TreeNode* root = new TreeNode(s);
        l.pop_front();
        root->left = deserializeDFS(l);
        root->right = deserializeDFS(l);
        return root;
    }


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


};

int main() {
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);
  TreeNode* node5 = new TreeNode(5);
  node1->left = node2;
  node1->right = node3;
  node3->left = node4;
  node3->right = node5;

  Solution* sln = new Solution();
  string str;
  str = sln->serialize(node1);
  cout << str << " " << endl;


  TreeNode *n = sln->deserialize(str);
  vector<int> result = sln->preorderTraversal(n);
  for(int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;





  return 0;
}
