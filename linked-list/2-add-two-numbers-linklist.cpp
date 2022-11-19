// low bit store at head of link list.
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

      ListNode* dummyNode = new ListNode(-1);
      ListNode* currNode = dummyNode;
      int carry = 0;
      for( ;l1 != nullptr || l2 != nullptr; currNode = currNode->next ) {
        int c1 = l1 == nullptr ? 0 : l1->val;
        int c2 = l2 == nullptr ? 0 : l2->val;
        int val = (c1 + c2 + carry) % 10;
        carry = (c1 + c2 + carry) / 10;
        currNode->next = new ListNode(val);

        l1 = l1 == nullptr ? nullptr : l1->next;
        l2 = l2 == nullptr ? nullptr : l2->next;
      }
      if (carry > 0) currNode->next = new ListNode(carry);
      return dummyNode->next;

    }
};


int main() {
  ListNode *l1 = new ListNode(2);
  ListNode *l2 = new ListNode(4);
  ListNode *l3 = new ListNode(3);
  l1->next = l2;
  l2->next = l3;

  ListNode *p1 = new ListNode(5);
  ListNode *p2 = new ListNode(6);
  ListNode *p3 = new ListNode(4);

  p1->next = p2;
  p2->next = p3;

  Solution* sln = new Solution();

  ListNode* result = sln->addTwoNumbers(l1, p1);

  while(result) {
    cout << result->val << " ";
    result = result->next;
  }
  cout << endl;
  return 0;
}
