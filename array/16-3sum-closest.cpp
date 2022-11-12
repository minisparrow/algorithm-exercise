
// https://leetcode.cn/problems/3sum-closest/
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int diff = INT_MAX;
    sort(nums.begin(), nums.end());
    int sum3;
    for (int i = 0; i < nums.size() - 1; i++) {
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
         sum3 = nums[left] + nums[right] + nums[i];
         if (abs(sum3 - target) < abs(diff)) {
           diff = sum3 - target;
         }
         if (sum3 < target) left++;
         else if (sum3 > target) right--;
         else return target;
      }
    }
    return diff + target;
  }
};

int main() {
  Solution* sln = new Solution();
  vector<int> nums{-1, 2, 1, -4};
  int target = 1;
  int result = sln->threeSumClosest(nums, target);
  cout << result << endl;
  return 0;
}
