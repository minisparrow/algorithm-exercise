#include <iostream>

using namespace std;
int main() {

  //========================================
  // malloc and free
  int *pNum2 = (int *)malloc(5 * sizeof(int));
  cout << "please input 5 numbers\n";
  for (auto i = 0; i < 5; ++i) {
    cin >> *(pNum2 + i);
  }
  cout << "your input is:\n";
  for (auto i = 0; i < 5; ++i) {
    cout << *(pNum2 + i) << endl;
  }
  free(pNum2);
}
