
// 宏定义  macro definition
#include <iostream>
using namespace std;

#define CONST(a, b) (int)a##e##b
#define STR(a) #a

int main() {
  int a = 1;
  int b = 2;
  int ab = 3;
  int aeb = 5;
  cout << STR(a) << endl;
  cout << CONST(a, b) << endl;
  // cout << CONST(a, e, b) << endl;
}
