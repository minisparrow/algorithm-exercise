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
  ListNode *reverseList(ListNode *head) {
    // input 1 -> 2 -> 3 -> 4 -> 5
    if (head == nullptr)
      return nullptr;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = curr->next;
    while (curr) {
      next = curr->next;
      curr->next = prev; // while main operation
      prev = curr;       // prev of next iteration
      curr = next;       // curr of next iteration
    }
    return prev;
  }

  /*
  //
  // ...  1. input
  // ...  +-------+-------+-------+-------+-------+
  // ...  |   1   |   2   |   3   |   4   |   5   |
  // ...  +-------+-------+-------+-------+-------+
  // ...              ^               ^
  // ...              |               |
  // ...            left            right
  //
  //
  // ...  2. find the prevnode, leftnode, right node, postnode
  // ...  +-------+-------+-------+-------+-------+
  // ...  |   1   |   2   |   3   |   4   |   5   |
  // ...  +-------+-------+-------+-------+-------+
  // ...      ^       ^               ^       ^
  // ...      |       |               |       |
  // ...    prev     leftNode     rightNode  post
  //
  //
  //      3. cut the prev node and rightnode
  // ...  +------+  +-+  +-------+-------+-------+  +-+     +------+
  // ...  |  1   +->| |  |   2   |   3   |   4   +->| |     |  5   |
  // ...  +------+  +-+  +-------+-------+-------+  +-+     +------+
  // ...      ^      |       ^               ^       |         ^
  // ...      |      |       |               |       |         |
  // ...    prev   null    leftNode     rightNode   null      post
  //
  //
  // ...  4. reverse
  // ...  +------+  +-+  +-------+-------+-------+  +-+     +------+
  // ...  |  1   +->| |  |   4   |   3   |   2   +->| |     |  5   |
  // ...  +------+  +-+  +-------+-------+-------+  +-+     +------+
  // ...      ^      |       ^                       |         ^
  // ...      |      |       |                       |         |
  // ...    prev   null    reverse                  null      post
  //
  //
  // ...  5. link
  // ...  +------+    +-------+-------+-------+    +------+
  // ...  |  1   +--->|   4   |   3   |   2   +--->|  5   |
  // ...  +------+    +-------+-------+-------+    +------+
  // ...      ^           ^                           ^
  // ...      |           |                           |
  // ...    prev        reverse                      post
  //
  // 6. return dummy->next
  //+------+    +------+   +------+    +-------+-------+-------+    +------+
  //|  -1  +--->|  1   +...|  1   +--->|   4   |   3   |   2   +--->|  5   |
  //+------+    +------+   +------+    +-------+-------+-------+    +------+
  //    ^           ^         ^           ^                           ^
  //    |           |         |           |                           |
  //  dummy       head      prev        reverse                      post
  //
  //
  */
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right)
      return head;
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;

    // 1. find the prev node and leftnode
    //  prev = left 前一个节点
    //  leftNode = left 指向的节点
    ListNode *prev = dummyNode;
    ListNode *leftNode = head;
    for (signed i = 0; i < left - 1; i++) {
      prev = prev->next;
      leftNode = leftNode->next;
    }
    prev->next = nullptr;

    // 2. find the rightnode and postnode
    // rightNode = right指向的节点
    ListNode *rightNode = leftNode;
    ListNode *post = nullptr;
    for (size_t i = 0; i < right - left; i++) {
      rightNode = rightNode->next;
    }
    post = rightNode->next;
    rightNode->next = nullptr;

    // 3. reverse the node between leftnode and rightnode
    ListNode *reverse = reverseList(leftNode);
    prev->next = reverse;
    for (size_t i = 0; i < right - left; i++) {
      reverse = reverse->next;
    }

    // 4. link the reverse node
    reverse->next = post;
    cout << "after reverse between " << left << " and " << right << endl;

    return dummyNode->next;
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
  // input 1 -> 2 -> 3 -> 4 -> 5
  // left = 2, right = 4
  // -->
  // output 1 -> 4 -> 3 -> 2 -> 5
  ListNode l1(1);
  ListNode l2(2);
  ListNode l3(3);
  ListNode l4(4);
  ListNode l5(5);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;

  int left = 2, right = 4;
  ListNode *resultList;
  Solution *sln = new Solution;
  sln->printList(&l1);
  resultList = sln->reverseBetween(&l1, left, right);
  sln->printList(resultList);
}

void test2() {
  // input 5
  // left = 1, right = 1
  // -->
  // output 5
  ListNode l1(5);
  l1.next = nullptr;

  int left = 1, right = 1;
  ListNode *resultList;
  Solution *sln = new Solution;
  sln->printList(&l1);
  resultList = sln->reverseBetween(&l1, left, right);
  sln->printList(resultList);
}

void test3() {
  // input 3 -> 5
  // left = 1, right = 2
  // -->
  // output 5 -> 3
  ListNode l1(3);
  ListNode l2(5);
  l1.next = &l2;
  l2.next = nullptr;

  int left = 1, right = 2;
  ListNode *resultList;
  Solution *sln = new Solution;
  sln->printList(&l1);
  resultList = sln->reverseBetween(&l1, left, right);
  sln->printList(resultList);
}

int main(int argc, char *argv[]) {
  // test1();
  test3();
  return 0;
}
