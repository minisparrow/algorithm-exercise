// case1: has loop
// 3   -> 2(p)  -> 0  -> -4   -> 2(p)
// 3sf -> 2(p)  -> 0  -> -4   -> 2(p)
// 3   -> 2(p)s -> 0f -> -4   -> 2(p)
// 3   -> 2(p)  -> 0s -> -4   -> 2(p)f
// 3   -> 2(p)  -> 0  -> -4sf -> 2(p)
//
// case2: no loop
// 3b -> 2  -> 0  -> -4
// 3  -> 2s -> 0f -> -4
// 3  -> 2  -> 0s -> -4 -> nullptr/f
//
// case2: no loop
// 3b -> 2  -> 0  -> -4 -> 5
// 3  -> 2s -> 0f -> -4 -> 5
// 3  -> 2  -> 0s -> -4 -> 5f -> nullptr
// b---------------------------------->
// -sf-------------------------------->
// --s-f------------------------------>
// ---s--f---------------------------->
// ----s---f-------------------------->
#include "utils/listnode-common.h"
class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        return true;
      }
    }
    return false;
  }
};
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(3);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(0);
  ListNode *l4 = new ListNode(-4);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l2;
  // printList(l1);
  Solution *sln = new Solution;
  cout << sln->hasCycle(l1) << endl;
  return 0;
}
