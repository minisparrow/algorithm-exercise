#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    int cnt = 0;
    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int sum;
    while (left < right) {
      sum = nums[left] + nums[right];
      if (sum == k) {
        left++;
        right--;
        cnt += 1;
      }
      if (sum < k) {
        left++;
      }
      if (sum > k) {
        right--;
      }
    }
    return cnt;
  }
};

int main(int argc, char *argv[]) {
  {
    vector<int> nums{2, 1, 3, 4};
    int k = 5;
    Solution *sln = new Solution;
    int res;
    res = sln->maxOperations(nums, k);
    cout << res << endl;
  }
  {
    vector<int> nums{3, 1, 3, 4, 3};
    int k = 6;
    Solution *sln = new Solution;
    int res;
    res = sln->maxOperations(nums, k);
    cout << res << endl;
  }
  return 0;
}
