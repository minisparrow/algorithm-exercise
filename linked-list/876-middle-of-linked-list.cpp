
// 1 -> 2 -> 3 -> 4 -> 5
// 1 -> 2 -> 3 -> 4 -> 5 -> 6
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *middle = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      // ==============================================
      // test1
      // 1 -> 2 -> 3 -> 4 -> 5
      // 1s/f -> 2 -> 3 -> 4 -> 5
      // 1 -> 2s -> 3f -> 4 -> 5
      // 1 -> 2 -> 3s -> 4 -> 5f (stop condition: fast->next == null)
      // test2
      // 1sf -> 2 -> 3 -> 4 -> 5 -> 6
      // 1 -> 2s -> 3f -> 4 -> 5 -> 6
      // 1 -> 2 -> 3s -> 4 -> 5f -> 6
      // 1 -> 2 -> 3 -> 4s -> 5 -> 6 -> nullptr/f( stop: fast == null)
      // ==============================================
      slow = slow->next;
      fast = fast->next->next;
    }
    middle = slow;

    return middle;
  }
  void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
      cout << curr->val << "->";
      curr = curr->next;
    }
    cout << "nullptr" << endl;
  }
};

void test1() {
  ListNode l1(1);
  ListNode l2(2);
  ListNode l3(3);
  ListNode l4(4);
  ListNode l5(5);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  l5.next = nullptr;
  Solution *sln = new Solution;
  sln->printList(&l1);
  ListNode *middle;
  middle = sln->middleNode(&l1);
  sln->printList(middle);
}
void test2() {
  ListNode l1(1);
  ListNode l2(2);
  ListNode l3(3);
  ListNode l4(4);
  ListNode l5(5);
  ListNode l6(6);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  l5.next = &l6;
  l6.next = nullptr;
  Solution *sln = new Solution;
  sln->printList(&l1);
  ListNode *middle;
  middle = sln->middleNode(&l1);
  sln->printList(middle);
}
int main(int argc, char *argv[]) {
  test1();
  test2();
  return 0;
}
