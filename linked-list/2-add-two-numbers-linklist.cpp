
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "utils/listnode-common.h"
class Solution {
public:
  // case 1----------
  // 2 4 3
  // 5 6 4
  // +
  // 7 0 8
  // case 2----------
  // 2 4 3
  // 5 6
  // +
  // 7 0 4
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummyNode = new ListNode(-1);
    ListNode *addNode = dummyNode;
    int valA;
    int valB;
    int carry = 0;
    int acc;
    while (l1 || l2) {
      valA = (l1 != nullptr) ? l1->val : 0;
      valB = (l2 != nullptr) ? l2->val : 0;

      acc = (valA + valB + carry) % 10;
      carry = (valA + valB + carry) / 10;

      addNode->next = new ListNode(acc);
      addNode = addNode->next;

      l1 = (l1 != nullptr) ? l1->next : nullptr;
      l2 = (l2 != nullptr) ? l2->next : nullptr;
    }
    if (carry)
      addNode->next = new ListNode(carry);
    return dummyNode->next;
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr1{2, 4, 3};
  vector<int> arr2{5, 6, 4};
  ListNode *l1 = arrayToListNode(arr1);
  ListNode *l2 = arrayToListNode(arr2);
  printList(l1);
  printList(l2);
  Solution *sln = new Solution;
  printList(sln->addTwoNumbers(l1, l2));
  return 0;
}
