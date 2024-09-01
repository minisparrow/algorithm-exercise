
#include <iostream>
#include <list>
using namespace std;
int main() {
  list<float> arr(5, 3);
  list<float>::iterator iter = arr.begin();
  // auto iter = arr.begin();
  for (; iter != arr.end(); ++iter) {
    cout << *iter << " ";
  }
  cout << endl;
  int i = 1;
  for (iter = arr.begin(); iter != arr.end(); ++iter) {
    *iter = i;
    ++i;
  }
  cout << "after change:" << endl;
  for (iter = arr.begin(); iter != arr.end(); ++iter) {
    cout << *iter << " ";
  }
  cout << endl;
  return 0;
}
