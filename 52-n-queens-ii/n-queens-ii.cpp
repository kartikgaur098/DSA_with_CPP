class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> lowerDiagnolCheck;
    unordered_map<int, bool> upperDiagnolCheck;

    bool isSafe(int row, int col) {
        if (rowCheck[row] || upperDiagnolCheck[row - col] ||
            lowerDiagnolCheck[row + col])
            return false;
        return true;
    }

    void solve(int n, int col, int& count) {
        if (col >= n) {
            count++;
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col)) {
                rowCheck[row] = true;
                lowerDiagnolCheck[row + col] = true;
                upperDiagnolCheck[row - col] = true;

                solve(n, col + 1, count);

                // backtrack
                rowCheck[row] = false;
                lowerDiagnolCheck[row + col] = false;
                upperDiagnolCheck[row - col] = false;
            }
        }
    }

    int totalNQueens(int n) {
        int count = 0;
        solve(n, 0, count);
        return count;
    }
};
