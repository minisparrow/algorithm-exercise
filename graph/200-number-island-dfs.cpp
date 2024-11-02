#include <iostream>
#include <vector>
using namespace std;
class Solution {

public:
  void dfs(vector<vector<char>> &grid, int x, int y, vector<vector<bool>> &visited) {
    int m = grid.size();
    int n = grid[0].size();
    // cur: [i][j]
    int dxdy[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (size_t i = 0; i < 4; i++) {
      int nextx = x + dxdy[i][0];
      int nexty = y + dxdy[i][1];
      if (nextx < 0 || nextx >= m || nexty < 0 || nexty >= n || grid[nextx][nexty] == '0')
        continue;
      if (grid[nextx][nexty] == '1' && !visited[nextx][nexty]) {
        visited[nextx][nexty] = true;
        dfs(grid, nextx, nexty, visited);
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
          dfs(grid, i, j, visited);
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
