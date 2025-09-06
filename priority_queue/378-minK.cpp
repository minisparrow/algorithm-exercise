#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  // int kthSmallest(vector<vector<int>> &matrix, int k) {
  //   vector<int> arr;
  //   for (auto &row : matrix) {
  //     for (auto &col : row) {
  //       arr.push_back(col);
  //     }
  //   }
  //   sort(arr.begin(), arr.end());
  //   return arr[k - 1];
  // }
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    auto lesser = [&](int left, int right) -> bool { return left < right; };
    priority_queue<int, vector<int>, decltype(lesser)> maxPQ(lesser);
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[0].size(); j++) {
        if (maxPQ.size() < k) {
          maxPQ.push(matrix[i][j]);
        } else {
          if (matrix[i][j] < maxPQ.top()) {
            maxPQ.pop();
            maxPQ.push(matrix[i][j]);
          }
        }
      }
    }
    return maxPQ.top();
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
  int k = 8;
  Solution *sln = new Solution;
  int res = sln->kthSmallest(matrix, k);
  cout << res << endl;
  return 0;
}
