#include <functional>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> father(n + 1, 0);
    // init
    function<void(int)> init = [&](int n) -> void {
      for (int i = 1; i < n + 1; i++) {
        father[i] = i;
      }
    };
    // find
    function<int(int)> find = [&](int u) -> int {
      if (u < 0 || u >= n + 1) {
        std::cerr << "Index out of bounds: " << u << std::endl;
        return -1; // Handle error appropriately
      }
      return u == father[u] ? u : father[u] = find(father[u]);
    };
    // join
    function<void(int, int)> join = [&](int u, int v) -> void {
      u = find(u);
      v = find(v);
      if (u == v)
        return;
      father[v] = u;
    };
    function<bool(int, int)> isSame = [&](int u, int v) -> bool {
      u = find(u);
      v = find(v);
      if (u == v)
        return true;
      return false;
    };
    auto isATreeAfterDeleteEdge = [&](vector<vector<int>> &edges, int delete_edge) -> bool {
      init(edges.size());
      for (int i = 0; i < n; ++i) {
        if (i == delete_edge)
          continue;
        if (isSame(edges[i][0], edges[i][1])) {
          return false;
        } else {
          join(edges[i][0], edges[i][1]);
        }
      }
      return true;
    };

    init(n);

    vector<int> indegree(n + 1, 0);
    vector<int> delete_edges;
    for (auto &edge : edges) {
      indegree[edge[1]]++;
    }

    // edges which indegree is 2, which need to be deleted one edge
    for (int i = n - 1; i >= 0; i--) {
      if (indegree[edges[i][1]] == 2) {
        delete_edges.push_back(i);
      }
    }

    if (delete_edges.size() > 0) {
      if (isATreeAfterDeleteEdge(edges, delete_edges[0]))
        return edges[delete_edges[0]];
      else {
        return edges[delete_edges[1]];
      }
    }
    for (auto &edge : edges) {
      if (isSame(edge[0], edge[1])) {
        return edge;
      } else {
        join(edge[0], edge[1]);
      }
    }
    return {};
  }
};

int main(int argc, char *argv[]) {
  Solution *sln = new Solution;
  // vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  // vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
  vector<vector<int>> edges = {{2, 1}, {3, 1}, {4, 2}, {1, 4}};
  vector<int> res;
  res = sln->findRedundantDirectedConnection(edges);
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
