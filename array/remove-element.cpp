#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      // slow --> fast
      unsigned int slow = 0;
      for (unsigned int fast = 0; fast < nums.size(); fast++) {
        if(nums[fast] != val) {
          nums[slow] = nums[fast];
          slow++;
        }
      }

      return slow;

    }
};

int main() {
  Solution* sln = new Solution();
  vector<int> nums{3,2,2,3};
  int val = 3;
  int length = sln->removeElement(nums, val);
  cout<< length << endl;
  return 0;
}
