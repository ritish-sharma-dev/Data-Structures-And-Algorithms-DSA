class Solution {
public:
    void f(int m, int n, vector<vector<char>> &grid, int i, int j){
        if (i < 0 || i >= m || j < 0 || j >= n) return;

        if (grid[i][j] == '0' || grid[i][j] == '2') return;

        grid[i][j] = '2';

        f(m, n, grid, i - 1, j);
        f(m, n, grid, i, j + 1);
        f(m, n, grid, i + 1, j);
        f(m, n, grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int islands = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] != '2' && grid[i][j] != '0'){
                    f(m, n, grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};