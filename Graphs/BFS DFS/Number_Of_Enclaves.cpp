// LEETCODE : 1020. Number of Enclaves

class Solution {

    // TC : O(m*n)
    // SC : O(m*n)

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if ( (i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1) q.push({ i, j });
            }
        }

        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            bfs(grid, m, n, row, col, q, vis);
            q.pop();
        }

        int cnt = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }

        return cnt;
    }

    void bfs(vector<vector<int>> &grid, int m, int n, int row, int col, queue<pair<int, int>> &q, vector<vector<int>> &vis){
        if (row < 0 || row >= m || col < 0 || col >= n) return;

        if (grid[row][col] == 0 || vis[row][col] == 1) return;

        vis[row][col] = 1;

        bfs(grid, m, n, row - 1, col, q, vis);
        bfs(grid, m, n, row, col + 1, q, vis);
        bfs(grid, m, n, row + 1, col, q, vis);
        bfs(grid, m, n, row, col - 1, q, vis);
    }
};