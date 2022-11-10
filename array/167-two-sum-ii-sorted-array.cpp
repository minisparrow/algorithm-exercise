// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while(left < right) {
      int sum = nums[left] + nums[right];
      if(sum < target) {
        left++;
      } else if(sum > target) {
        right--;
      } else {
        return {left+1, right+1};
      }
    }
    return {-1, -1};
  }
};


int main() {
  Solution* sln = new Solution();
  vector<int> nums{2,7,11,15};
  int target = 9;
  vector<int> expect{1,2};
  vector<int> result;
  result = sln->twoSum(nums, target);
  for(int i = 0; i < 2; i++) {
    cout << result[i] << "|" <<  expect[i] << endl;
    assert(result[i]  == expect[i]);
  }
}
