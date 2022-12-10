#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
      if (node == nullptr) return nullptr;
      queue<Node*> que;
      que.push(node);
      unordered_map<Node* , Node*> visitedMap;

      visitedMap[node] = new Node(node->val);

      while(!que.empty()) {
        Node* n = que.front();
        que.pop();

        for(auto& neighbour : n->neighbors) {
          // if not visited,
          // push neighbour to que,
          // push neighbour to visited map
          if (visitedMap.find(neighbour) == visitedMap.end()) {
            que.push(neighbour);
            visitedMap[neighbour] = new Node(neighbour->val);
          }

          //copy neighbours to current node
          visitedMap[n]->neighbors.emplace_back(visitedMap[neighbour]);
        }
      }

      return visitedMap[node];
    }
    void printGraph(Node* node) {
      queue<Node*> que;
      que.push(node);
      vector<vector<int>> adjList;
      unordered_map<Node* , int> visitedMap;

      visitedMap[node] = 1;
      vector<int> init{node->val};
      adjList.emplace_back(init);

      while(!que.empty()) {
        Node* n = que.front();
        que.pop();

        vector<int> temp;
        for(auto& neighbour : n->neighbors) {
          // if not visited,
          // push neighbour to que,
          // push neighbour to visited map
          if (visitedMap.find(neighbour) == visitedMap.end()) {
            que.push(neighbour);
            visitedMap[neighbour] = 1;
            temp.emplace_back(neighbour->val);
          }
        }
        adjList.emplace_back(temp);
      }

      for (int i = 0; i < adjList.size(); i++) {
        for (int j = 0; j < adjList[i].size(); j++){
          cout << adjList[i][j] << ",";
        }
        cout << endl;
      }
      cout << endl;
    }
};


int main()
  {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    Solution* sln = new Solution();
    Node * result = sln->cloneGraph(n1);
    //cout << result->val << endl;
    sln->printGraph(result);
    return 0;
  }
