#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int bfs(vector<vector<int>> &grid, int y, int x, vector<vector<bool>> &visited) {
    int area = 1;
    int m = grid.size();
    int n = grid[0].size();
    int dxdy[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    queue<std::pair<int, int>> que;
    que.push({y, x});
    visited[y][x] = true;
    while (!que.empty()) {
      auto front = que.front();
      auto y = front.first;
      auto x = front.second;
      que.pop();
      for (size_t i = 0; i < 4; i++) {
        int nexty = y + dxdy[i][0];
        int nextx = x + dxdy[i][1];
        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
          continue;
        if (grid[nexty][nextx] == 1 && !visited[nexty][nextx]) {
          visited[nexty][nextx] = true;
          area += 1;
          que.push({nexty, nextx});
        }
      }
    }
    return area;
  }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = 0;
    int area;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (!visited[i][j] && grid[i][j] == 1) {
          visited[i][j] = true;
          // 1.label with visted
          area = bfs(grid, i, j, visited);
          maxArea = max(maxArea, area);
        }
      }
    }
    return maxArea;
  }
};
int main(int argc, char *argv[]) {
  Solution *sln = new Solution;
  vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  int res = sln->maxAreaOfIsland(grid);
  cout << "max area of island is " << res << endl;
  return 0;
}
