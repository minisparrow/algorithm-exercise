// https://leetcode.cn/problems/move-zeroes/

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      // slow --> fast
      unsigned int slow = 0;
      for (unsigned int fast = 0; fast < nums.size(); fast++) {
        if(nums[fast] != 0) {
          nums[slow] = nums[fast];
          slow++;
        }
      }
      for (unsigned int i = slow; i < nums.size(); i++) {
         nums[i] = 0;
      }
    }
};

int main() {
  Solution* sln = new Solution();
  vector<int> nums{0,3,0,2,2,3};
  sln->moveZeroes(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " " << endl;
  }
  return 0;
}
