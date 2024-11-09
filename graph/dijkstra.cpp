#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

// 定义一个结构表示图中的边
struct Edge {
  int destination;
  int weight;
  Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Dijkstra 算法函数
vector<int> dijkstra(int start, const vector<vector<Edge>> &graph) {
  int n = graph.size();
  vector<int> distances(n, numeric_limits<int>::max()); // 初始化距离为无穷大
  distances[start] = 0;

  // 最小堆，存储 (距离, 节点) 对
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
  minHeap.push({0, start});

  while (!minHeap.empty()) {
    auto [currentDistance, currentNode] = minHeap.top();
    minHeap.pop();

    // 如果当前距离已经不是最短，则跳过
    if (currentDistance > distances[currentNode]) {
      continue;
    }

    // 遍历当前节点的邻接边
    for (const auto &edge : graph[currentNode]) {
      int neighbor = edge.destination;
      int newDist = currentDistance + edge.weight;

      // 如果通过当前节点可以获得更短的路径，更新距离
      if (newDist < distances[neighbor]) {
        distances[neighbor] = newDist;
        minHeap.push({newDist, neighbor});
      }
    }
  }

  return distances;
}

int main() {
  // 构建图（使用邻接列表表示）
  int numNodes = 5;
  vector<vector<Edge>> graph(numNodes);

  // 添加边
  graph[0].push_back(Edge(1, 4));  // A -> B (4)
  graph[0].push_back(Edge(2, 1));  // A -> C (1)
  graph[1].push_back(Edge(3, 2));  // B -> D (2)
  graph[2].push_back(Edge(3, 5));  // C -> D (5)
  graph[2].push_back(Edge(4, 12)); // C -> E (12)
  graph[3].push_back(Edge(4, 3));  // D -> E (3)

  int startNode = 0; // 从节点 A 开始
  vector<int> distances = dijkstra(startNode, graph);

  // 输出结果
  cout << "从节点 A 开始的最短路径距离：" << endl;
  for (int i = 0; i < distances.size(); ++i) {
    cout << "A -> " << char('A' + i) << ": ";
    if (distances[i] == numeric_limits<int>::max()) {
      cout << "无穷大" << endl;
    } else {
      cout << distances[i] << endl;
    }
  }

  return 0;
}
