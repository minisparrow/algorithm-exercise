//https://leetcode.cn/problems/3sum/description/
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> twoSum(int value, int left, int right, vector<int>& nums){

      vector<vector<int>> result;

      while(left < right) {
         int sum = nums[left] + nums[right] + value;
         if(sum == 0) {
           vector<int> oneSeq;
           oneSeq.push_back(value);
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

    vector<vector<int>> threeSum(vector<int>& nums) {
      //sort nums;
      sort(nums.begin(), nums.end());
      vector<vector<int>> temp_result;
      vector<vector<int>> result;
      for (int i = 0; i < nums.size(); i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int value = nums[i];
        temp_result = twoSum(value, i+1, nums.size()-1, nums);
        result.insert(result.end(), temp_result.begin(), temp_result.end());
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
  for(int i = 0; i < expectResult.size(); i++) {
    for(int j = 0; j < 3; j++) {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
