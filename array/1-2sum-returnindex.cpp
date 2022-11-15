#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> nums, int target) {
    map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
      numMap[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
      auto elem = numMap.find(target - nums[i]);
      if (elem != numMap.end() && elem->second > i) {
        return {i, elem->second};
      }
    }
    return {-1, -1};
  }
};

int main() {
  Solution* sln = new Solution();
  vector<int> nums{2,7,11,15};
  int target = 9;
  vector<int> result;
  result = sln->twoSum(nums, target);
  for(int i = 0; i < result.size(); i++) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
