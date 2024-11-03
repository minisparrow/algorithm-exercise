#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> indegree(numCourses, 0);
    unordered_map<int, vector<int>> node_map;
    // 1. init indegree
    for (size_t i = 0; i < prerequisites.size(); i++) {
      indegree[prerequisites[i][0]]++;
      node_map[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    queue<int> que;
    vector<int> res;
    for (size_t i = 0; i < numCourses; i++) {
      if (indegree[i] == 0)
        que.push(i);
    }

    while (!que.empty()) {
      auto front = que.front();
      que.pop();
      res.push_back(front);
      vector<int> adjacent = node_map[front];
      for (int i = 0; i < adjacent.size(); ++i) {
        indegree[adjacent[i]]--;
        if (indegree[adjacent[i]] == 0)
          que.push(adjacent[i]);
      }
    }

    if (res.size() == numCourses)
      return true;
    return false;
  }
};

int main(int argc, char *argv[]) {
  int numCourses = 2;
  // vector<vector<int>> prerequisites{{1, 0}, {0, 1}};
  vector<vector<int>> prerequisites{{1, 0}};
  Solution *sln = new Solution;
  bool res = sln->canFinish(numCourses, prerequisites);
  if (res)
    cout << "can Finish" << endl;
  else
    cout << "can not Finish" << endl;
  return 0;
}
