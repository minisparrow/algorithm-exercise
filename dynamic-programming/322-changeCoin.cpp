
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    // 动态规划三步
    // 1. 状态定义
    // dp[i] 表示凑成总金额i所需的最少的硬币个数,我们求的就是dp[amout]
    // 2. 状态方程
    // dp[i] ?= dp[i-coin], 金额i所需要的硬币个数, 与(金额i-某个coin)的硬币个数的关系
    // dp[i] = min(dp[i-coin] + 1, dp[i])
    // 3. 初始化
    // dp[0] = 0; dp[1] = amount+1
    int n = coins.size();
    vector<int> dp(amount + 1, amount + 1); // 选的硬币可以无限重复，所以个数不能设置为n+1
    dp[0] = 0;                              // 凑成0元所需最少硬币个数为0

    for (size_t i = 1; i <= amount; i++) { // 外层循环表示凑层i的金额
      for (auto coin : coins) {            // 内层循环表示选择到第j个coin的时候
        if (i - coin >= 0)
          dp[i] = min(dp[i - coin] + 1, dp[i]);
        // dp[i-j]表示金额为i-j时所需的最少硬币个数,所以dp[i]就只需要在dp[i-j]的个数上加1即可。
      }
    }

    // 如果dp[amount]值大于coins的个数
    return dp[amount] <= amount ? dp[amount] : -1;
  }
};

int main() {
  // vector<int> coins{1, 2, 5};
  // int amount = 11;
  vector<int> coins{1};
  int amount = 2;
  int result;
  Solution *sln = new Solution();
  result = sln->coinChange(coins, amount);
  cout << result << endl;
  return 0;
}
