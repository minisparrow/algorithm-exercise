#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val{x}, next{next} {};
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    //  q walk n step first
    //  then q and p walk together, when q walk to the end, remove next p
    ListNode dummy{-1, head};
    ListNode *q = &dummy;
    ListNode *p = &dummy;

    for(int i = 0; i < n; i++ ){
        q = q->next;
    }

    while(q->next != nullptr) {
        q = q->next;
        p = p->next;
    }
    ListNode* deleteNode = p->next;
    p->next = p->next->next;
    delete deleteNode;
    return dummy.next;
    }
};

int main() {
  ListNode *l1 = new ListNode(3);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(0);
  ListNode *l4 = new ListNode(-4);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;

  Solution *sln = new Solution();
  bool result = sln->removeNthFromEnd(l1, 2);
  while(l1) {
    cout << l1->val << endl;
    l1 = l1->next;
  }

  return 0;
}
