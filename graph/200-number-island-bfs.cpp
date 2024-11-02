#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  void bfs(vector<vector<char>> &grid, int y, int x, vector<vector<bool>> &visited) {
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
        if (grid[nexty][nextx] == '1' && !visited[nexty][nextx]) {
          visited[nexty][nextx] = true;
          que.push({nexty, nextx});
        }
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    int counter = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (!visited[i][j] && grid[i][j] == '1') {
          visited[i][j] = true;
          // 1.label with visted
          bfs(grid, i, j, visited);
          // 2.couter+1
          counter++;
        }
      }
    }
    return counter;
  }
};
int main(int argc, char *argv[]) {
  Solution *sln = new Solution;
  vector<vector<char>> grid{{'1', '1', '0', '0', '0'},
                            {'1', '1', '0', '0', '0'},
                            {'0', '0', '1', '0', '0'},
                            {'0', '0', '0', '1', '1'}};
  int res = sln->numIslands(grid);
  cout << "there are " << res << " islands" << endl;
  return 0;
}
