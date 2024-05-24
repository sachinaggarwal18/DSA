#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    bool isSafe(int col, int row, vector<string>& board, int n) {
        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check the same column upwards
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void solve(int row, vector<string>& board, int n) {
        // Base case
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(col, row, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, board, n);
        return res;
    }
};

int main() {
    int n = 4; // You can change n to solve for different sizes of the board
    Solution obj;
    vector<vector<string>> solutions = obj.solveNQueens(n);

    for (const auto& board : solutions) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
