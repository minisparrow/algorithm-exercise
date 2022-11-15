//https://leetcode.cn/problems/longest-consecutive-sequence/
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    set<int> numSet;
    for (auto num: nums) {
      numSet.insert(num);
    }
    int longest = 1;
    for (int i = 0; i < nums.size(); i++) {
      int length = 1;
      int centerNum = nums[i];
      // find num bigger than centerNum
      for (int num = centerNum + 1; numSet.find(num) != numSet.end(); ++num) {
        numSet.erase(num);
        length += 1;
      }
      // find num smaller than centerNum
      for (int num = centerNum - 1; numSet.find(num) != numSet.end(); --num) {
        numSet.erase(num);
        length += 1;
      }
      longest = max(longest, length);
    }
    return longest;
  }

};

int main() {
  vector<int> nums{100,4,200,2,3,1};
  int expect=4;
  Solution* sln = new Solution();
  int result = sln->longestConsecutive(nums);
  cout << result << endl;
  return 0;
}
