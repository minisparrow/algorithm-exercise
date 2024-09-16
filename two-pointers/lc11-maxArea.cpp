#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int maxArea(vector<int> &height) {
    int max_area = 0;
    int size = height.size();

    int left = 0;
    int right = size - 1;
    int curr_area;
    while (left < right) {
      curr_area = min(height[left], height[right]) * (right - left);
      if (curr_area > max_area) {
        max_area = curr_area;
      }

      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return max_area;
  }
};

int main(int argc, char *argv[]) {
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution *sln = new Solution;
  int res;
  res = sln->maxArea(height);
  cout << res << endl;
  return 0;
}
