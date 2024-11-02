#include <iostream>
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
    // for (auto &y : graph[x]) {
    for (size_t i = 1; i <= end; i++) {
      if (graph[x][i] == 1) {
        path.push_back(i);
        dfs(graph, i, end);
        path.pop_back();
      }
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph, int start, int end) {
    path.push_back(start);
    dfs(graph, start, end);
    return res;
  }
};

int main(int argc, char *argv[]) {
  int n, m; // n nodes, m edges
  int s, e; // s start, e end
  cout << "input number of nodes and edges" << endl;
  cin >> n >> m;
  cout << "start and end" << endl;
  vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

  while (m--) {
    cin >> s >> e; // s start, e end
    graph[s][e] = 1;
  }
  cout << "graph build end" << endl;
  Solution *sln = new Solution;
  vector<vector<int>> res;

  res = sln->allPathsSourceTarget(graph, 1, n);

  if (res.size() == 0)
    cout << -1 << endl;
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[i].size() - 1; j++) {
      cout << res[i][j] << " ";
    }
    cout << res[i][res[i].size() - 1] << endl;
  }
  return 0;
}
