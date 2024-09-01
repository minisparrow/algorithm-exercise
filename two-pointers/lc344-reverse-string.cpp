
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int size = s.size();
    for (int left = 0, right = size - 1; left < right; left++, right--) {
      swap(s[left], s[right]);
    }
  }
  void printString(vector<char> &s) {
    for (auto i : s) {
      cout << i << " ";
    }
    cout << endl;
  }
};

int main() {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  Solution *sln = new Solution;
  sln->reverseString(s);
  sln->printString(s);

  return 0;
}
