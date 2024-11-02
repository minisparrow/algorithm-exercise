#include <functional>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
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

    init(n);
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
  vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
  vector<int> res;
  res = sln->findRedundantConnection(edges);
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
