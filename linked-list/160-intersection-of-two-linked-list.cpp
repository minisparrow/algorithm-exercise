

#include "utils/listnode-common.h"

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //       a1 -> a2 -> c1 -> c2 -> c3
    // b1 -> b2 -> b3 --
    // a:  --o--|---o
    // b:  ---o--|--o
    // a: pa + c + pb
    // b: pb + c + pa

    ListNode *pa = headA;
    ListNode *pb = headB;
    while (pa != pb) {
      if (pa != nullptr)
        pa = pa->next;
      else
        pa = headB;
      if (pb != nullptr)
        pb = pb->next;
      else
        pb = headA;
    }
    return pa;
  }
};

int main(int argc, char *argv[]) {
  ListNode *a1 = new ListNode(4);
  ListNode *a2 = new ListNode(1);
  ListNode *c1 = new ListNode(8);
  ListNode *c2 = new ListNode(4);
  ListNode *c3 = new ListNode(5);
  ListNode *b1 = new ListNode(5);
  ListNode *b2 = new ListNode(6);
  ListNode *b3 = new ListNode(1);
  a1->next = a2;
  a2->next = c1;
  c1->next = c2;
  c2->next = c3;
  b1->next = b2;
  b2->next = b3;
  b3->next = c1;
  printList(a1);
  printList(b1);
  Solution *sln = new Solution;
  ListNode *res;
  res = sln->getIntersectionNode(a1, b1);
  printList(res);
  return 0;
}
