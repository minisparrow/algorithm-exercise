#include <iostream>
using namespace std;

int *func0() {
  static int a = 10;
  return &a; // 返回局部变量的地址
}

int *func() {
  int a = 10;
  return &a; // 返回局部变量的地址
}

int main() {
  int *pNum = new int(5);
  cout << *pNum << endl;
  delete pNum;
  pNum = nullptr;
  pNum = new int(6);
  cout << *pNum << endl;

  int *p = func();
  // p 是一个野指针，因为 a 的生命周期在 func() 返回时就结束了
  cout << *p << endl;
  return 0;
}
