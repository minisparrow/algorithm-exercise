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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 0 -> left-1 
        ListNode *dummy = new ListNode(-1); 
        dummy->next = head;

        ListNode *prev = dummy;
        for (int i = 0; i < left -1 ; ++i) {
            prev = prev->next; 
        }

        ListNode *region_before = prev;


        ListNode *region_prev = prev->next; 
        ListNode *region_curr = region_prev->next; 

        // left -> right (reverse the region node)
        for (int i = left; i < right; ++i) {
            ListNode *next = region_curr->next; 
            region_curr->next = region_prev;    
            region_prev = region_curr;          
            region_curr = next;                
        }

        //region prev is  the head of reversed region node
        ListNode *end = region_prev; 
        region_before->next = end;
         
        //  get the end of reverse node 
        ListNode *right_node = end; 
        for (int i = right; i > left; --i) {
            right_node = right_node->next; 
        }
        right_node->next = region_curr; 
        return dummy->next; 
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
  ListNode *l1 = new ListNode(2);
  ListNode *l2 = new ListNode(3);
  ListNode *l3 = new ListNode(4);
  ListNode *l4 = new ListNode(5);
  l0->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;

  Solution* sln = new Solution();
  int left = 2, right = 4;

  sln->printList("original list", l0);
  ListNode* result = sln->reverseBetween(l0, left, right);
  sln->printList("after reverse", result);

  return 0;
}


