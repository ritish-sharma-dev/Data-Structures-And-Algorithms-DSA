// LEETCODE : 994. Rotting Oranges

class Solution {

    // TC : O(m*n)
    // SC : O(m*n)

public:
    using P = pair<pair<int, int>, int>;

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<P> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2) q.push({ {i, j}, 0 });
            }
        }

        int minutes = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            minutes = max(minutes, time);
            q.pop();

            for (int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
                    q.push({{ nRow, nCol }, time + 1 });
                    vis[nRow][nCol] = 1;
                }
            }
        }


        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1 && vis[i][j] != 1) return -1;
            }
        }

        return minutes;
    }
};