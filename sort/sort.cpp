#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> insertSort(vector<int>& arr) {
    // {9, 10, 2, 1, 5};
    int len = arr.size();
    for (int i = 1; i < len; i++) {
       // current elem as insert elem, prev sequence is sorted well.
       // insert elem to sorted sequence
       int insert_elem = arr[i];
       int position = i;
       while (position > 0 && insert_elem < arr[position - 1]) {
         arr[position] = arr[position - 1];
         position = position - 1;
       }
       arr[position] = insert_elem;
    }

    return arr;
  }
};

int main() {
  Solution* sln = new Solution();
  vector<int> arr{9, 10, 2, 1, 5};
  vector<int> res = sln->insertSort(arr);
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
