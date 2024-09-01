#include <iostream>
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// node
// {val, next}->
// {1, next}-> {2, next}-> {3, next} -> {4, next}->{5, next}
// after reverse
// {5, next}-> {4, next}-> {3, next} -> {2, next}->{1, next}
//
//             curr
// curr->prev<--|---------->curr->next
// {1, next}-> {2, next}-> {3, next} -> {4, next}->{5, next}
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *curr = head;
    if (!curr)
      return nullptr;
    ListNode *prev = nullptr;
    ListNode *next = curr->next;
    while (curr) {       //
      next = curr->next; // 保存下一个节点
      curr->next = prev; // 更新当前节点的下一个节点（指向前一个节点）
      prev = curr; // 更新下一个前向节点
      curr = next; // 更新下一个当前节点
    }
    return prev; // 注意这里返回的应该是prev而不是curr,此时curr是空指针。
  }
};

using namespace std;
void printListNode(ListNode *head) {
  ListNode *curr = head;
  while (curr) {
    cout << curr->val << endl;
    curr = curr->next;
  }
}
int main() {
  ListNode p1(1);
  ListNode p2(2);
  ListNode p3(3);
  ListNode p4(4);
  ListNode p5(5);
  p1.next = &p2;
  p2.next = &p3;
  p3.next = &p4;
  p4.next = &p5;
  Solution *sln = new Solution;
  printListNode(&p1);
  ListNode *reverse = sln->reverseList(&p1);
  cout << "after reverse:" << endl;
  printListNode(reverse);
  return 0;
}
