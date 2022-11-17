
#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode *lista = headA;
        ListNode *listb = headB;
        while(lista != listb) {
            lista = lista == nullptr ? headB : lista->next;
            listb = listb == nullptr ? headA : listb->next;
        }

        return lista;
    }
};


int main() {
  // intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
  ListNode *listA;
  ListNode *listB;
  ListNode *l1 = new ListNode(4);
  ListNode *l2 = new ListNode(1);
  ListNode *l3 = new ListNode(8);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);
  listA = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  ListNode *p1 = new ListNode(5);
  ListNode *p2 = new ListNode(6);
  ListNode *p3 = new ListNode(1);
  ListNode *p4 = new ListNode(8);
  ListNode *p5 = new ListNode(4);
  ListNode *p6 = new ListNode(5);

  listB = p1;
  p1->next = p2;
  p2->next = p3;
  p3->next = p4;
  p4->next = p5;
  p5->next = p6;

  Solution *sln = new Solution();
  ListNode *result = sln->getIntersectionNode(listA, listB);
  cout << result->val << endl;

}
