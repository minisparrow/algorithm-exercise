
#include <iostream>
#include <vector>
using namespace std;

// **输入：**nums = [10,9,2,5,3,7,101,18]
// **输出：**4
// **解释：**最长递增子序列是 [2,3,7,101]，因此长度为 4 。

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    // 动态规划三部曲
    // 1. 状态定义
    // 设 dp[i] 是以i结尾的最长递增子序列
    // 2. 状态转移函数
    // dp[i]  ?= dp[j], j < i
    // if nums[i] > nums[j], 那么dp[i]长度加1， 否则长度不变
    // 3. 初始化
    // dp[0] = 1
    // 这个题的关键是要定义好dp[i],是以i为结尾的递增序列,
    // 然后就是需要两层for循环来遍历, 因为需要比较后面的值是否比前面最长序列的最后一个值大
    if (nums.size() == 0)
      return 0;
    vector<int> dp(nums.size(), 1);
    int maxL = 1;
    // 0, 1, ..., j, ..., i
    for (size_t i = 1; i < nums.size(); i++) {
      for (size_t j = 0; j < i; j++) {
        if (nums[i] > nums[j])
          dp[i] = max(dp[j] + 1, dp[i]); // 当然也有可能dp[j] + 1 小于原来的dp[i],所以要取个最大值
        // 如果nums[i] < nums[j] ， dp[i]值保持不变
      }
      // 对于每一个dp[i], 要和之前的dp值取最大值
      maxL = max(maxL, dp[i]);
    }
    return maxL;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  Solution *sln = new Solution;
  int res = sln->lengthOfLIS(nums);
  cout << res << endl;

  return 0;
}
