// LEETCODE - 37


class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char ch) {
        for (int k = 0; k <= 8; k++) {
            if (board[i][k] == val)
                return false;
        }

        for (int k = 0; k <= 8; k++) {
            if (board[k][j] == val)
                return false;
        }

        int r = i / 3 * 3;
        int c = i / 3 * 3;
        for (int k = r; k <= r + 2; k++) {
            for (int l = c; l <= c + 2; l++) {
                if (board[k][l] == val)
                    return false;
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (check(board, i, j, ch)) {
                            board[i][j] = ch;
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
    }
}
}
;