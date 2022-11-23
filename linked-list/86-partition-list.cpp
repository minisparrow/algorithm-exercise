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
    ListNode* partition(ListNode* head, int x) {
       ListNode* dummy_left = new ListNode(-1);
       ListNode* dummy_right = new ListNode(-1);

       ListNode* left_curr = dummy_left;
       ListNode* right_curr = dummy_right;

       for (ListNode* curr = head;  curr != nullptr; curr = curr->next) {
           if (curr->val < x) {
               left_curr->next = curr;
               left_curr = left_curr->next;
           } else {
               right_curr->next = curr;
               right_curr = right_curr->next;
           }
       }
       left_curr->next = dummy_right->next;
       right_curr->next = nullptr;
       return dummy_left->next;
    }

    void printList(string msg,  ListNode* lst) {
       cout << msg << " : ";
       while(lst) {
         cout << lst->val << " ";
         lst = lst->next;
       }
       cout << endl;
    }
};


int main() {
  ListNode *l0 = new ListNode(1);
  ListNode *l1 = new ListNode(4);
  ListNode *l2 = new ListNode(3);
  ListNode *l3 = new ListNode(2);
  ListNode *l4 = new ListNode(5);
  ListNode *l5 = new ListNode(2);
  l0->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  Solution* sln = new Solution();
  int x = 3;

  sln->printList("original list", l0);
  ListNode* result = sln->partition(l0, x);
  sln->printList("after partition", result);

  return 0;
}
