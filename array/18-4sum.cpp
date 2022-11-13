// 4sum
#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      //pseudo algorithm
      //1. sort
      //2. kSum(nums, target, k)
      //3. kSum -> recursive -> kSum -> 2Sum
      vector<vector<int>> result;
      sort(nums.begin(), nums.end());
      result = kSum(nums, 0, (long int)target, 4);
      return result;
    }
private:
    vector<vector<int>> kSum(vector<int>& nums, int start, long int target, int k) {
      vector<vector<int>> result;
      if (k == 2) {
        return twoSum(nums, start, target);
      }

      if (start + k > nums.size() || ((long int)nums[start] * k) > target) {

        return result;
      }

      for(unsigned int i = start; i < nums.size(); i++) {
        if (i == start || nums[i - 1] != nums[i]) {
          for(auto &list : kSum(nums, i+1, target - nums[i], k - 1)) {
            list.insert(list.begin(), nums[i]);
            result.push_back(list);

          }
        }
      }

      return result;

    }


    // big data may overflow, so target type is long int
    vector<vector<int>> twoSum(vector<int>& nums, int start, long int target){
      cout<< "start: "<< start << endl;
      vector<vector<int>> result;
      int left = start;
      int right = nums.size() - 1;
      while(left < right) {
         int sum = nums[left] + nums[right];
         if(sum == target) {
           vector<int> oneSeq;
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
         } else if (sum < target) {
           left++;
         } else if (sum > target) {
           right--;
         }
      }

      return result;
    }
};


int main() {
  Solution* sln = new Solution();
  //vector<int> nums = {1,0,-1,0,-2,-2};
  //vector<int> nums = {1,0,-1,0,-2,2};
  // vector<int> nums = {2,2,2,2,2};
  // int target = 8;
  // big data overflow
  // vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
  // int target = 0;
  vector<int> nums = {-1000000000,-1000000000,1000000000,-1000000000,-1000000000};
  int target = 294967296;
  vector<vector<int>> output;
  output = sln->fourSum(nums, target);
  for(int i = 0; i < output.size(); i++) {
    for(int j = 0; j < 4; j++) {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
