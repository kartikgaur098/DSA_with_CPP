class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> upperDiagonalCheck;
    unordered_map<int, bool> lowerDiagonalCheck;

    void storeSolution(vector<vector<string>> &ans, vector<vector<char>> &board, int n) {
        vector<string> temp;
        for (int i = 0; i < n; ++i) {
            string row = "";
            for (int j = 0; j < n; ++j) {
                row += board[i][j];
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col) {
        if (rowCheck[row] || upperDiagonalCheck[row - col] || lowerDiagonalCheck[row + col])
            return false;
        return true;
    }

    void solve(int n, int col, vector<vector<char>> &board, vector<vector<string>> &ans) {
        if (col >= n) {
            storeSolution(ans, board, n);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperDiagonalCheck[row - col] = true;
                lowerDiagonalCheck[row + col] = true;

                solve(n, col + 1, board, ans);

                // Backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                upperDiagonalCheck[row - col] = false;
                lowerDiagonalCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        solve(n, 0, board, ans);
        return ans;
    }
};
