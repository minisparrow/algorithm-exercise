// 1 -> 2 -> 3 -> 4 -> 5
#include "utils/listnode-common.h"
using namespace std;

void test1() {
  vector<int> arr{1, 2, 3, 4, 5};
  ListNode *l1 = arrayToListNode(arr);
  printList(l1);
}
int main(int argc, char *argv[]) {
  test1();
  return 0;
}
