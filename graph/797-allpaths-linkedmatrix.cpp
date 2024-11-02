#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;

  void dfs(vector<vector<int>> &graph, int x, int end) {
    if (x == end) {
      res.push_back(path);
      return;
    }
    for (auto &y : graph[x]) {
      path.push_back(y);
      dfs(graph, y, end);
      path.pop_back();
    }
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph, int start, int end) {
    path.push_back(start);
    dfs(graph, start, end);
    return res;
  }
};

int main(int argc, char *argv[]) {

  vector<vector<int>> graph{{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
  int nodes = graph.size();

  cout << "graph build end" << endl;
  Solution *sln = new Solution;
  vector<vector<int>> res;

  res = sln->allPathsSourceTarget(graph, 0, nodes - 1);
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
