
#include <iostream>
using namespace std;
int main() {
  int a;
  a = 1;
  cout << "leading 1 position of " << a << " is: " << __builtin_ctzll(a) << endl;
  a = 2;
  cout << "leading 1 position of " << a << " is: " << __builtin_ctzll(a) << endl;
  a = 4;
  cout << "leading 1 position of " << a << " is: " << __builtin_ctzll(a) << endl;
  a = 8;
  cout << "leading 1 position of " << a << " is: " << __builtin_ctzll(a) << endl;
  a = 12;
  cout << "leading 1 position of " << a << " is: " << __builtin_ctzll(a) << endl;
  return 0;
}
