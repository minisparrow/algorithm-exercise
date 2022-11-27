class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr) return nullptr; 
       // 1. get length of list 
       // 2. rotate k =  node shift (len - k % len) times
       int length = 1; 
       ListNode* curr = head;
       while (curr->next != nullptr) {
           length += 1; 
           curr = curr->next;
       } 

       int shift = length - k % length; 
       curr->next = head; 

       for (int step = 0; step < shift; step++) {
           curr = curr->next; 
       }

       ListNode* returnList = curr->next; 
       curr->next = nullptr; 
       return returnList; 
    }
};
