// 
// https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75

#include <cassert>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


// bfs, breadth first search
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //3:33 
        int dx[4] = {0,  0, -1, 1}; 
        int dy[4] = {-1, 1, 0,  0};  // up, down, left, right

        //get maze size
        int height = maze.size(); 
        int width = maze[0].size();

        //result 
        int step = 0; 
        //queue 
        queue<pair<int, int> > curPosition;
        //initial queue
        curPosition.push({entrance[0], entrance[1]});

        bool visited[height][width];
        memset(visited, 0, sizeof visited);
        visited[entrance[0]][entrance[1]] = true;

        while(!curPosition.empty()) 
        {
             step++; 
             int sz = curPosition.size(); 
             for (int j = 0; j < sz; ++j)
             {
                auto [y, x] = curPosition.front(); 
                curPosition.pop(); 
                for (int i = 0; i < 4; ++i) 
                {
                    //new position
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    // position is in maze and is space
                    if (nx >=0 && nx < width && ny >=0 && ny < height && !visited[ny][nx] && maze[ny][nx] == '.')  
                    {
                        // position is the extrance border
                        if (nx == 0 || nx == width - 1 || ny == 0 || ny == height - 1) {
                            return step;
                        } 
                        curPosition.push({ny, nx}); // for next step tranverse
                        visited[ny][nx] = true;
                    }
                }
             }
        }

        return -1;    
    }
};


void test1()
{

    //  +---+---+---+---+                                         
    //  | + | + | . | + |
    //  +---+---+---+---+                                         
    //  | . | . | o | + |
    //  +---+---+---+---+                                         
    //  | + | + | + | . |
    //  +---+---+---+---+                                         
                                                   
    vector<vector<char>> maze { {'+', '+', '.', '+'},
                                {'.', '.', '.', '+'},
                                {'+', '+', '+', '.'} };
    vector<int> entrance = {1, 2};
    int expect = 1;

    Solution *sln; 
    int step;
    step = sln->nearestExit(maze, entrance);
    assert(step == expect);
    cout <<"expect is:" << expect << " calcute is: " << step << endl;
}

void test2()
{
    //  +---+---+---+                         
    //  | + | + | + |                         
    //  +---+---+---+                         
    //  | o | . | . |                         
    //  +---+---+---+                         
    //  | + | + | + |                         
    //  +---+---+---+                         
    vector<vector<char>> maze { {'+','+','+'},
                                {'.','.','.'},
                                {'+','+','+'}};
    vector<int> entrance = {1, 0};
    int expect = 2;

    Solution *sln; 
    int step;
    step = sln->nearestExit(maze, entrance);
    assert(step == expect);
    cout <<"expect is:" << expect << " calcute is: " << step << endl;
}

void test3()
{
    // +---+---+        
    // | o | + |        
    // +---+---+        
    vector<vector<char> > maze = {{'.', '+'}};
    vector<int> entrance = {0, 0};
    int expect = -1;

    Solution *sln; 
    int step;
    step = sln->nearestExit(maze, entrance);
    assert(step == expect);
    cout <<"expect is:" << expect << " calcute is: " << step << endl;
}


int main() 
{
    test1();
    test2();
    test3();
    return 0;
}
