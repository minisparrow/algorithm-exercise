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
  bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
       slow = slow->next;
       fast = fast->next->next;
       if(slow == fast) {
         return true;
       };
    }
    return false;
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
  l4->next = l2;

  // while (l1) {
  //   cout<< l1->val << endl;
  // }

  Solution *sln = new Solution();
  bool result = sln->hasCycle(l1);
  cout << result << endl;

  return 0;
}
