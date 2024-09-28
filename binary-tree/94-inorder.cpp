#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Definition for a binary tree node.
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
  vector<int> res;
  vector<int> inorderTraversal(TreeNode *root) {
    //        1
    //         󰁃
    //          2
    //         󰁂
    //        3
    if (!root)
      return {};
    inorderTraversal(root->left);
    res.push_back(root->val);
    inorderTraversal(root->right);
    return res;
  }
  // op: init  | s:         | res: {}            | curr=root=5
  //
  // op: push  | s: 5,      | res: {}            | curr: 5
  // op: left  | s: 5,      | res: {}            | curr=curr.left, curr: 4
  //
  // op: push  | s: 5, 4,   | res: {}            | curr: 4
  // op: left  | s: 5, 4    | res: {}            | curr=curr.left, curr: 1
  //
  // op: push  | s: 5, 4, 1 | res: {}            | curr: 1
  // op: left  | s: 5, 4, 1 | res: {}            | curr=curr.left, curr: null
  //
  // op: right | s: 5, 4, 1 | res: {}            | curr=top,curr=curr.right,curr:null
  // op: pop   | s: 5, 4    | res: {1}           | curr:null
  //
  // op: right | s: 5, 4    | res: {1}           | curr=top,curr=curr.right,curr:2
  // op: pop   | s: 5,      | res: {1, 4}        | curr:2
  //
  // op: push  | s: 5, 2    | res: {1, 4}        | curr:2
  // op: left  | s: 5, 2    | res: {1,4}         | curr=curr.left, curr: null
  //
  // op: right | s: 5, 2    | res: {1,4}         | curr=top,curr=curr.right,curr:null
  // op: pop   | s: 5,      | res: {1, 4, 2}     | curr:null
  //
  // op: right | s: 5       | res: {1,4,2 }      | curr=top,curr=curr.right,curr:6
  // op: pop   | s:         | res: {1, 4, 2, 5}  | curr:6
  //
  // op: push  | s: 6       | res: {1, 4, 2, 5}  | curr:6
  // op: left  | s: 6       | res: {1, 4, 2, 5}  | curr=curr.left, null
  //
  // op: right | s: 6       | res: {1,4,2,5}     | curr=top,curr=curr.right,curr:null
  // op: pop   | s:         | res: {1, 4, 2,5,6} | curr:null
  //
  vector<int> inorderTraversalWithStack(TreeNode *root) {
    //        5
    //       󰁂 󰁃
    //      4   6
    //     󰁂 󰁃
    //    1   2
    //   󰁂 󰁃
    // null null
    // remember 3 keypoints:
    // 1. 访问节点， 和处理节点
    // 2. curr指针非空时，push and left
    // 3. curr指针为空时，right and pop
    // 4. 当curr 和 stk都是空的时候停止操作
    if (!root)
      return {};
    stack<TreeNode *> stk{};
    vector<int> res{};
    TreeNode *curr = root;
    while (curr || !stk.empty()) {
      if (curr) { // push and left
        stk.push(curr);
        curr = curr->left;
      } else { // right and pop
        curr = stk.top();
        stk.pop();
        res.push_back(curr->val);
        curr = curr->right;
      }
    }

    return res;
  }
  vector<int> inorderTraversalWithLabledStack(TreeNode *root) {
    //        5
    //       󰁂 󰁃
    //      4   6
    //     󰁂 󰁃
    //    1   2
    //   󰁂 󰁃
    // null null
    // inorder:  左 中 右
    // stack push:  右 中 左
    // 初始化的节点：白色，表示没访问过
    // =====================================================================
    // 3 operations:
    // 1. pop:
    // 2. white: push -> stack {右中左元素push到stack, 中间节点标记为black}
    // 3. black，表示访问过，push_back -> vector
    // =====================================================================
    // init               | s: {5, white}
    // s is not empty, while start
    // pop                | s: {}                                          | 判断top, color = 5, white
    // white -> push      | s: {6-white, 5-black, 4-white}
    // pop                | s{6-white, 5-black,}                           | 判断top, color = 4, white
    // white -> push      | s{6-white, 5-black, 2-white, 4-black, 1-white}
    // pop                | s{6-white, 5-black, 2-white, 4-black}          | jude top, color = 1-white
    // white -> push      | s{6-white, 5-black, 2-white, 4-black, 1-black}
    // pop                | s{6-white, 5-black, 2-white, 4-black}          | top, color =  1-black
    // black -> push_back | s{6-white, 5-black, 2-white, 4-black}          | res {1}
    // pop                | s{6-white, 5-black, 2-white                    | top, color =  4-black
    // black -> push_back | s{6-white, 5-black, 2-white                    | res {1, 4}
    // pop                | s{6-white, 5-black},                           | top, color = 2-white
    // white -> push      | s{6-white, 5-black, 2-black}
    // pop                | s{6-white, 5-black                             | top, color = 2-black
    // black -> push_back | s{6-white, 5-black                             | res {1, 4, 2}
    // pop                | s{6-white,                                     | top, color = 5-black
    // black -> push_back | s{6-white}                                     | res {1, 4, 2, 5}
    // pop                | s {}                                           | top, color = 6-white
    // white -> push      | s:{6-black}
    // pop                | s{}                                            | top, color= 6-black
    // black -> push_back | s {}                                           | res {1, 4, 2, 5, 6}
    // s is empty, stop
    // =====================================================================
    if (!root)
      return {};
    vector<int> res;
    enum Color { white = 0, black };
    Color color;
    TreeNode *top;
    stack<std::pair<TreeNode *, Color>> stk;
    stk.push(make_pair(root, white)); // init
    while (!stk.empty()) {
      // top, color = stk.top();
      auto tops = stk.top();
      top = tops.first;
      color = tops.second;
      stk.pop();
      if (top)
        if (color == white) {
          stk.push({top->right, white});
          stk.push({top, black});
          stk.push({top->left, white});
        } else {
          res.push_back(top->val);
        }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *t0 = new TreeNode(1);
  TreeNode *t1 = new TreeNode(2);
  TreeNode *t2 = new TreeNode(3);
  t0->right = t1;
  t1->left = t2;
  Solution *sln = new Solution;
  // vector<int> res = sln->inorderTraversal(t0);
  // vector<int> res = sln->inorderTraversalWithStack(t0);
  vector<int> res = sln->inorderTraversalWithLabledStack(t0);
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
