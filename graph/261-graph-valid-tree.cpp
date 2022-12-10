// 263- Graph valid tree
// Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
// Example 1:
// Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
// Output: true
//
// Example 2:
//
// Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
// Output: false
//
// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
//
//

#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
  public:
  // 一个图是一颗树，当且仅当它满足如下两个条件：
  // 1. 图是全连通的。对于图中的任意两点，至少存在一条路径连接它俩。
  // 2. 图里没有环。对于图中的任意两点，有且仅有一条路径。
  // 可以用 DFS 和 BFS 遍历图，在遍历的过程中检查是否满足上述两个条件。如果某个结点被访问了两次，说明存在环；遍历结束后，如果访问过的结点数量小于图中结点总数，说明图不是全连通的。
  // bfs queue
  bool validTreeBFS(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;
    // construct graph/adjacent list
    vector<vector<int>> adj_list(n);
    for(vector<int>& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }
    // bfs
    queue<int> que;
    unordered_set<int> visited;
    que.push(0);
    visited.insert(0);
    while(!que.empty()) {
      int front = que.front();
      que.pop();

      for(auto& endpoint: adj_list[front]) {
        if (visited.count(endpoint)) continue;
        que.push(endpoint);
        visited.insert(endpoint);
      }
    }

    return visited.size() == n;
  }

  // dfs stack
  bool validTreeDFS(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;
    // construct graph/adjacent list
    vector<vector<int>> adj_list(n);
    for(vector<int>& edge : edges) {
      adj_list[edge[0]].push_back(edge[1]);
      adj_list[edge[1]].push_back(edge[0]);
    }
    // bfs
    stack<int> stk;
    unordered_set<int> visited;
    stk.push(0);
    visited.insert(0);
    while(!stk.empty()) {
      int front = stk.top();
      stk.pop();

      for(auto& endpoint: adj_list[front]) {
        if (visited.count(endpoint)) continue;
        stk.push(endpoint);
        visited.insert(endpoint);
      }
    }

    return visited.size() == n;
  }
};

int main()
  {
    int n = 5;
    vector<vector<int>> edges = {{0,1}, {0,2}, {0,3}, {1,4}};
    bool expect = true;
    Solution* sln = new Solution();
    bool  resultBFS = sln->validTreeBFS(n, edges);
    bool  resultDFS = sln->validTreeDFS(n, edges);
    cout << "graph is valid tree BFS ? " << resultBFS << endl;
    cout << "graph is valid tree DFS ? " << resultDFS << endl;
    return 0;
  }
