#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    // 动态规划
    // 1. 状态定义
    // dp[i][j] 表示text1[0..i - 1] 和text2[0..j - 1] 的公共子序列长度
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 因为要用到dp[m][n]
    // 2. 状态转移
    // 3. 初始化
    for (size_t i = 1; i <= m; i++) {
      for (size_t j = 1; j <= n; j++) {
        if (text1[i - 1] == text2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[m][n];
  }
};
