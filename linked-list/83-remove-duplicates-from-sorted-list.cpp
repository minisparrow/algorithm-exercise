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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)  return nullptr;
        ListNode* newList = new ListNode(-1);
        ListNode* dummyNode = newList;

        newList->next = head;
        newList = newList->next;
        int val = head->val;

        for (ListNode* i = head->next; i != nullptr; i = i->next) {
            if (i->val !=  val) {
               newList->next = i;
               val = i->val;
               newList = newList->next;
            }
        }
        newList->next = nullptr;

        return dummyNode->next;

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
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(3);
    l0->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    Solution* sln = new Solution();

    sln->printList("original list", l0);
    ListNode* result = sln->deleteDuplicates(l0);
    sln->printList("after delete", result);

    return 0;
}
