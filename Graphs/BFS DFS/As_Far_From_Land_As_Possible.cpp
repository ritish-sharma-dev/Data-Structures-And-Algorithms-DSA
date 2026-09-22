// LEETCODE - 1162. As Far from Land as Possible

class Solution {

    // n = size of matrix
    // TC : O(n^2)
    // SC : O(n^2)

public:
    using P = pair<pair<int, int>, int>;

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<P> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    q.push({{ i, j }, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int maxDist = 0;
        while (!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            maxDist = max(maxDist, dist);

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && vis[nRow][nCol] == 0){
                    q.push({{ nRow, nCol }, dist + 1});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        return maxDist == 0 ? -1 : maxDist;
    }
};