// case1: has loop
// 3   -> 2(p)  -> 0  -> -4   -> 2(p)
// 3sf -> 2(p)  -> 0  -> -4   -> 2(p)
// 3   -> 2(p)s -> 0f -> -4   -> 2(p)
// 3   -> 2(p)  -> 0s -> -4   -> 2(p)f
// 3   -> 2(p)  -> 0  -> -4sf -> 2(p)
//
// case1: has loop
// 3   -> 2(p)  -> 0  -> -4  -> 5   -> 2(p)
// 3sf -> 2(p)  -> 0  -> -4  -> 5   -> 2(p)
// 3   -> 2(p)s -> 0f -> -4  -> 5   -> 2(p)
// 3   -> 2(p)  -> 0s -> -4  -> 5f  -> 2(p)
// 3   -> 2(p)  -> 0f -> -4s -> 5   -> 2(p)
// 3   -> 2(p)  -> 0  -> -4  -> 5sf -> 2(p)
//
// case1: has loop
// 3   -> 2  -> 0  -> -4(p)   -> 5  -> -4(p)
// 3sf -> 2  -> 0  -> -4(p)   -> 5  -> -4(p)
// 3   -> 2s -> 0f -> -4(p)   -> 5  -> -4(p)
// 3   -> 2  -> 0s -> -4(p)   -> 5f -> -4(p)
// 3   -> 2  -> 0  -> -4(p)s  -> 5f -> -4(p)
// 3   -> 2  -> 0  -> -4(p)   -> 5sf -> -4(p)
//
//
// s-------------o------x------------o
// |------a------|--b---|-----c------|
// o: 交叉点
// x: 快慢指针相遇点
// 相遇时快指针走的路程是慢指针的两倍：2(a + b) = a + b + c + b
// 从公式得出： a = c,
// 即从相遇点到交叉点的距离， 与起始点到交叉点距离相同
//
// case2: no loop
// 3b -> 2  -> 0  -> -4
// 3  -> 2s -> 0f -> -4
// 3  -> 2  -> 0s -> -4 -> nullptr/f
//
// case2: no loop
// 3b -> 2  -> 0  -> -4 -> 5
// 3  -> 2s -> 0f -> -4 -> 5
// 3  -> 2  -> 0s -> -4 -> 5f -> nullptr
// b---------------------------------->
// -sf-------------------------------->
// --s-f------------------------------>
// ---s--f---------------------------->
// ----s---f-------------------------->
//
#include "utils/listnode-common.h"
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    // s-------------o------x------------o
    // |------a------|--b---|-----c------|
    // o: 交叉点
    // x: 快慢指针相遇点
    // 相遇时快指针走的路程是慢指针的两倍：2(a + b) = a + b + c + b
    // 从公式得出： a = c,
    // 即从相遇点到交叉点的距离， 与起始点到交叉点距离相同
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        ListNode *third = head;
        while (third != slow) {
          third = third->next;
          slow = slow->next;
        }
        return third;
      }
    }
    return nullptr;
  }
};
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(3);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(0);
  ListNode *l4 = new ListNode(-4);
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l2;
  // printList(l1);
  Solution *sln = new Solution;
  cout << sln->detectCycle(l1)->val << endl;
  printList(sln->detectCycle(l1));
  return 0;
}
