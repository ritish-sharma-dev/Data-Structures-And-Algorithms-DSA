// LEETCODE : 542. 01 Matrix

class Solution {

    // m = no of rows, n = no of cols
    // TC : O(m * n)
    // SC : O(m * n)

public:
    using P = pair<pair<int, int>, int>;
    using V = vector<int>;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<V> ans(m, vector<int>(n, 0)), vis(m, vector<int>(n, 0));

        queue<P> q;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0){
                    q.push({{ i, j }, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            if (mat[row][col] == 1) ans[row][col] = dist;

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n){
                    if (vis[nRow][nCol] == 0){
                        q.push({{ nRow, nCol }, dist + 1});
                        vis[nRow][nCol] = 1;
                    }
                }
            }

        }

        return ans;
    }
};