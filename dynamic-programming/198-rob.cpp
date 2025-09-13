#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    // 从题目得知，不能去相邻的两个房间偷窃，否则会报警，所以必须得要隔开1到n个房间偷窃
    // 但是我们并不知道要隔几个房间去偷，如果遍历会很耗时
    // 显然求解可以用动态规划
    // 问题：求n个房间拿到的最大金额
    // 1. 问题拆解，状态定义 dp[i] 表示去第i个房间后，拿到的金额总数
    // 2. 状态转移方程:
    // - dp[i] = dp[i-2] + nums[i];  //在第i个房间去偷金钱
    // - dp[i] = dp[i-1];//在第i个房间不去偷金钱, 最大金钱是i-1房间后得到的金额总数
    // 3. 初始化
    vector<int> dp(nums.size(), 0);
    if (nums.size() == 1)
      return nums[0];
    dp[0] = nums[0];               // 从0计数，第0个房间
    dp[1] = max(nums[0], nums[1]); // 不能相加，因为不能连续取
    for (size_t i = 2; i < nums.size(); i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[nums.size() - 1];
  }
};

int main() {
  vector<int> nums{1, 2, 3, 1};
  Solution *sln = new Solution();
  cout << sln->rob(nums) << endl;
  return 0;
}
