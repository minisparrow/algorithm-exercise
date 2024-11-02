#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool isValid(int row, int col, char val, vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) { // 判断行里是否重复
      if (board[row][i] == val) {
        return false;
      }
    }
    for (int j = 0; j < 9; j++) { // 判断列里是否重复
      if (board[j][col] == val) {
        return false;
      }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
      for (int j = startCol; j < startCol + 3; j++) {
        if (board[i][j] == val) {
          return false;
        }
      }
    }
    return true;
  }
  bool backtracking(vector<vector<char>> &board) {
    int ROW = board.size();
    int COL = board[0].size();

    for (size_t i = 0; i < ROW; i++) {
      for (size_t j = 0; j < COL; j++) {
        if (board[i][j] == '.') {
          for (char k = '1'; k <= '9'; k++) {
            cout << i << "-" << j << ":" << k << endl;
            if (isValid(i, j, k, board)) {
              board[i][j] = k;
              bool filled = backtracking(board);
              if (filled)
                return true;
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }
  void solveSudoku(vector<vector<char>> &board) { backtracking(board); }
};

int main(int argc, char *argv[]) {
  vector<vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  Solution *sln = new Solution;
  sln->solveSudoku(board);
  for (size_t i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << ",";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
