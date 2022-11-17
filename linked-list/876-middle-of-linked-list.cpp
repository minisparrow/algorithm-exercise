#include <iostream>
#include <vector>
#include <list>
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

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

  // while (l1) {
  //   cout<< l1->val << endl;
  // }

  Solution *sln = new Solution();
  ListNode* result = sln->middleNode(l1);
  cout << result->val << endl;

  return 0;
}
