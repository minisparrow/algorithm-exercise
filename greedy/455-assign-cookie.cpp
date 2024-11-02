#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    // cake: s[j]  1 1
    // child: g[i] 1 2 3
    // if s[j] <= g[i]:
    //.  res++; and j++, i++
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;
    for (int i = 0, j = 0; i < g.size() && j < s.size();) {
      if (s[j] <= g[i]) {
        res++;
        i++;
        j++;
      } else {
        i++;
      }
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  vector<int> s{1, 1};
  vector<int> g{1, 2, 3};
  Solution *sln = new Solution;
  int res = sln->findContentChildren(g, s);
  cout << res << endl;
  return 0;
}
