//https://leetcode.cn/problems/3sum/description/
//
//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

// 你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。
//
// 示例 1：
//
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。
// 示例 2：
//
// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。


#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      //sort nums;
      sort(nums.begin(), nums.end());
      vector<vector<int>> result;
      for (int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        vector<vector<int>> temp_result;
        int start = i + 1;
        temp_result = twoSum(nums, start, 0);
        result.insert(result.end(), temp_result.begin(), temp_result.end());
      }

      return result;

    }
private:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target){
      cout<< "start: "<< start << endl;
      vector<vector<int>> result{};
      int left = start;
      int right = nums.size() - 1;
      while(left < right) {
         int sum = nums[start-1] + nums[left] + nums[right];
         if(sum == target) {
           vector<int> oneSeq;
           oneSeq.push_back(nums[start]);
           oneSeq.push_back(nums[left++]);
           oneSeq.push_back(nums[right--]);
           result.push_back(oneSeq);

           // skip the same number
           while (nums[left] == nums[left-1] && left < right) {
             left++;
           }
           while(nums[right] == nums[right+1] && left < right) {
             right--;
           }
         } else if (sum < 0) {
           left++;
         } else if (sum > 0) {
           right--;
         }
      }
      return result;
    }
};



int main() {
  Solution* sln = new Solution();
  vector<int> nums = {-1,0,1,2,-1,-4};
  vector<vector<int>> expectResult = {{-1,-1,2}, {-1,0,1}};
  // vector<int> nums = {0,0,0};
  // vector<vector<int>> expectResult = {{0,0,0}};
  vector<vector<int>> output;
  output = sln->threeSum(nums);
  for(int i = 0; i < output.size(); i++) {
    for(int j = 0; j < 3; j++) {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
