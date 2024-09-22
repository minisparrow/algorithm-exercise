#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    // head: 1 -> 4 -> 3 -> 2 -> 5 ->2 -> nullptr
    // x = 3
    // leftnode : 1 -> 2 -> 2
    // rightnode: 4 -> 3 -> 5
    // leftnode -> rightnode
    ListNode *leftDummy = new ListNode(-1);
    ListNode *rightDummy = new ListNode(-1);
    ListNode *leftnode = leftDummy;
    ListNode *rightnode = rightDummy;
    ListNode *curr = head;
    while (curr) {
      // partition
      if (curr->val < x) {
        leftnode->next = curr;
        leftnode = leftnode->next;
      } else {
        rightnode->next = curr;
        rightnode = rightnode->next;
      }
      curr = curr->next;
    }
    // leftnode : 1 -> 2 -> 2 ->
    // rightnode: 4 -> 3 -> 5 -> nullptr.......
    // rightDummy:  -1 -> (rightnode)
    // leftDummy:  -1 -> (leftnode)
    rightnode->next = nullptr;
    leftnode->next = rightDummy->next;
    return leftDummy->next;
  }
  void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
      cout << curr->val << "->";
      curr = curr->next;
    }
    cout << "nullptr" << endl;
  }
};

// 1 -> 4 -> 3 -> 2 -> 5->2
// 1 -> 4 -> 3 -> 2 -> 2->5 // this test will cause heap use after free issue in
// leetcode if not add nullptr after rightnode->next
int main() {
  ListNode l1(1);
  ListNode l2(4);
  ListNode l3(3);
  ListNode l4(2);
  ListNode l5(5);
  ListNode l6(2);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  l5.next = &l6;
  l6.next = nullptr;
  Solution *sln = new Solution;
  sln->printList(&l1);
  int x = 3;
  ListNode *res = sln->partition(&l1, x);
  sln->printList(res);
  return 0;
}
