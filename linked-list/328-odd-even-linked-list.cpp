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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddDummy = new ListNode(0); 
        ListNode* evenDummy = new ListNode(0); 
        ListNode* odd = oddDummy;
        ListNode* even = evenDummy;
        int index = 1; 
        while(head) {
            if (index % 2 == 1){  //odd
                 odd->next = head;
                 odd = odd->next; 
            } else { //even
                 even->next = head;
                 even = even->next;
            }
            ListNode *tmp = head->next;
            //head->next = nullptr; // why this statement
            head = tmp;

            ++index; 
        }

        odd->next = evenDummy->next;
        return oddDummy->next;

    }
};
