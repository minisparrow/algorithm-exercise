#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // 1. nums -> hashmap[nums 的值: 频率 ]
    map<int, int> mapOfFreq;
    for (size_t i = 0; i < nums.size(); i++) {
      mapOfFreq[nums[i]] += 1;
    }

    auto greater = [&](pair<int, int> left, pair<int, int> right) -> bool {
      return left.second > right.second;
    };

    // 2. minHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(greater)> minHeap(greater);

    for (auto [num, freq] : mapOfFreq) {
      if (minHeap.size() < k) {
        minHeap.push({num, freq});
      } else {
        auto [topnum, topfreq] = minHeap.top();
        if (freq > topfreq) {
          minHeap.pop();
          minHeap.push({num, freq});
        }
      }
    }
    vector<int> res;
    while (!minHeap.empty()) {
      auto [num, freq] = minHeap.top();
      minHeap.pop();
      res.push_back(num);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> nums{1, 1, 1, 2, 2, 3};
  int k = 2;
  Solution *sln = new Solution;
  vector<int> res = sln->topKFrequent(nums, k);
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
