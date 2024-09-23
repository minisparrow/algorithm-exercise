#include <iostream>
#include <vector>
using namespace std;
#include "listnode-common.h"

void printList(ListNode *head) {
  ListNode *curr = head;
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << "nullptr" << endl;
}

ListNode *arrayToListNode(vector<int> &array) {
  ListNode *dummyNode = new ListNode(-1);
  ListNode *head = dummyNode;
  // dummy:  -1, next -> nullptr
  // head : -1, next -> nullptr
  ListNode *node = nullptr;
  for (size_t i = 0; i < array.size(); i++) {
    // node :  (i, next -> nullptr)
    node = new ListNode(array[i]);
    // head : -1, next -> (i, next)-> nullptr
    // dummy: -1, next -> (i, next)-> nullptr
    head->next = node;
    head = head->next;
  }
  head->next = nullptr;
  return dummyNode->next;
}

void api_test() {
  vector<int> arr{1, 2, 3, 4, 5};
  ListNode *ln = nullptr;
  ln = arrayToListNode(arr);
  printList(ln);
}

// int main(int argc, char *argv[]) {
//   api_test();
//   return 0;
// }
