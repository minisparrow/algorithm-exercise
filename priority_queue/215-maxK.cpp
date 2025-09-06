#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minPQ;
    for (int i = 0; i < nums.size(); i++) {
      if (minPQ.size() < k) {
        minPQ.push(nums[i]);
      } else {
        if (nums[i] > minPQ.top()) {
          minPQ.pop();
          minPQ.push(nums[i]);
        }
      }
    }
    return minPQ.top();
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr{3, 2, 1, 5, 6, 4};
  int k = 2;
  Solution *sln = new Solution;
  int res = sln->findKthLargest(arr, k);
  cout << "max k number is:" << res << endl;
  return 0;
}
