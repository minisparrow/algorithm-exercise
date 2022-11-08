#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution{
  public:
     int removeDuplicates(vector<int>& nums) {
       //thoughts:   fast and slow pointer
       //walk through vector array using fast pointer, and
       //then update slow pointer
       unsigned slow = 0;
       for (unsigned int fast = 0; fast < nums.size(); ++fast) {
          if(nums[fast] != nums[slow]) {
            nums[slow+1] = nums[fast];
            slow++;
          }
       }
       return slow + 1;
     }
};

int main() {
  Solution* sln = new Solution();

  vector< vector<int>> nums{{1,1,2},  {2,3,4,5,5}};
  vector< int> expectedNums{2, 5};
  for (unsigned int i = 0; i < expectedNums.size(); i++) {
     int length = sln->removeDuplicates(nums[i]);
     assert(length == expectedNums[i]);
  }
  return 0;
}
