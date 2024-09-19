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
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = curr->next;
    while (curr) {
      // l1(1, next)->l2(2, next) -> l3(3, next) -> l4(4, next)
      // -> l5(5, next) -> nullptr
      next = curr->next;
      curr->next = prev; // main body
      // next iteration
      prev = curr;
      curr = next;
    }
    return prev;
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

int main(int argc, char *argv[]) {
  // l1(1, next)->l2(2, next) -> l3(3, next) -> l4(4, next)
  // -> l5(5, next) -> nullptr
  ListNode l1(1);
  ListNode l2(2);
  ListNode l3(3);
  ListNode l4(4);
  ListNode l5(5);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  l5.next = nullptr;
  Solution *sln = new Solution;
  sln->printList(&l1);
  ListNode *reverseList;
  reverseList = sln->reverseList(&l1);
  cout << "after reverse:" << endl;
  sln->printList(reverseList);
  return 0;
}
