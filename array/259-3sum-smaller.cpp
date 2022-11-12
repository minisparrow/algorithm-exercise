// > 描述
// Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
//
// Follow up: Could you solve it in O(n^2n
// 2
//  ) runtime?
//
// Example 1:
//
// Input: nums = [-2,0,1,3], target = 2
//
// Output: 2
//
// Explanation: Because there are two triplets which sums are less than 2:
//
// [-2,0,1]
//
// [-2,0,3]
//
// Example 2:
//
// Input: nums = [], target = 0
//
// Output: 0
//
// Example 3:
//
// Input: nums = [0], target = 0
//
// Output: 0
//
// Constraints:
//
// n == nums.length
// 0 <= n <= 300
// -100 <= nums[i] <= 100
// -100 <= target <= 100
//
// > 分析
// 先排序，然后双指针左右夹逼，复杂度 O(n^2)。
#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {

public:
  int threeSumSmaller(vector<int>& nums, int target) {
    int counter = 0;
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());

    //three sum question convert to two sum question
    for(size_t i = 0; i < nums.size(); i++) {
      counter += twoSumSmaller(nums, i+1, target - nums[i]);
    }
    return counter;
  }

private:
  int twoSumSmaller(vector<int> &nums, int start, int target) {
   int left = start;
   int right = nums.size() - 1;
   int counter = 0;
   while (left < right) {
     if (nums[left] + nums[right] < target) {
       counter += right - left;
       left++;
     } else if(nums[left] + nums[right]  >= target ) {
       right--;
     }
   }
   return counter;
  }
};

int main() {
  Solution* sln = new Solution();
  std::vector<int> nums{-2,0,1,3};
  int target = 2;
  int expect = 2;
  int counter;
  counter = sln->threeSumSmaller(nums, target);
  assert(counter == expect);
  cout<< counter << endl;
  return 0;
}
