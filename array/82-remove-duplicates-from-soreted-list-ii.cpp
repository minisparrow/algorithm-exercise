
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* curr = dummy;
        while(curr->next && curr->next->next) {
            if(curr->next->val == curr->next->next->val) {
                int x = curr->next->val;

                // update curr->next
                while(curr->next && curr->next->val == x) {
                    curr->next = curr->next->next;
                }
            } else {

                // update curr
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
