
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 1. 状态定义  dp[i] = 爬上i阶有多少种方法
// 2. 状态转移方程   dp[i] 与 dp[i-1]的关系，与dp[i-2]的关系， 大规模问题与小规模问题的关系
//  dp[i] = 爬上i的方法数= 可以由i-1 step再爬一层楼dp[i-1] + 或者由i-2 step再爬两层楼dp[i-2]
//
//  即: dp[i] = dp[i-1] + dp[i-2]
// 3. 状态初始化 dp[0] = 1; dp[1] = 1, dp[2] = 2

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

int main() {
  Solution *sln = new Solution;
  cout << sln->climbStairs(2) << endl;
  return 0;
}
