// LEETCODE 51. N-Queens



class Solution {
public:
    bool cannotKillAnyQueen(int row, int col, int n, vector<string>& s, vector<vector<string>>& sol) {

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (s[i][j] == 'Q') return false;
        }

        for (int x = 0; x < col; x++) {
            if (s[row][x] == 'Q') return false;
        }

        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (s[i][j] == 'Q') return false;
        }

        return true;
    }

    void f(int col, int n, vector<string>& s, vector<vector<string>>& sol) {
        if (col == n) {
            sol.push_back(s);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (cannotKillAnyQueen(row, col, n, s, sol)) {
                s[row][col] = 'Q';

                f(col + 1, n, s, sol);

                s[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> s(n, string(n, '.'));

        f(0, n, s, sol);

        return sol;
    }
};