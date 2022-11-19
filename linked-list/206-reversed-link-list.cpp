
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
    ListNode* reverseList(ListNode* head) {
       // old: prev -> curr
       // reverse : prev <- curr

       ListNode* prev = nullptr; 
       ListNode* curr = head; 
       while(curr) {
           ListNode *next = curr->next;
           curr->next = prev;
           //update prev and curr
           prev = curr;
           curr = next;
       }
       return prev;
    }
};
