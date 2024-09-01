
#include <iostream>

using namespace std;
int main() {
  //========================================
  // new and delete
  int *pNum = new int[5];
  cout << "please input 5 numbers\n";
  for (auto i = 0; i < 5; ++i) {
    cin >> *(pNum + i);
  }
  cout << "your input is:\n";
  for (auto i = 0; i < 5; ++i) {
    cout << *(pNum + i) << endl;
  }
  delete[] pNum;
  pNum = nullptr;
}
