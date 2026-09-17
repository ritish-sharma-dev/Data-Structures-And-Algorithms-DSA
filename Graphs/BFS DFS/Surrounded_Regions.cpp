// LEETCODE : 130. Surrounded Regions

class Solution {

    // m = no of rows, n = no of cols
    // TC : O(m * n)
    // SC : O(m * n)

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1){
                    if (board[i][j] == 'O') {
                        q.push({ i, j });
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n){
                    if (board[nRow][nCol] == 'O' && vis[nRow][nCol] == 0){
                        q.push({ nRow, nCol });
                        vis[nRow][nCol] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 'O' && vis[i][j] == 0) board[i][j] = 'X';
            }
        }
    }
};