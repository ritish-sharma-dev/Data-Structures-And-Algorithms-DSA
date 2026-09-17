class Solution {

    // m = no of rows, n = no of cols
    // TC : O(m*n)
    // SC : O(m*n)

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(),n = image[0].size();

        vector<vector<int>> ans = image;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;
        q.push({ sr, sc });
        
        int startingColor = ans[sr][sc];

        ans[sr][sc] = color;
        vis[sr][sc] = 1;


        while (!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++){
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];
                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && vis[nRow][nCol] == 0 && ans[nRow][nCol] == startingColor){
                    q.push({ nRow, nCol });
                    ans[nRow][nCol] = color;
                    vis[nRow][nCol] = 1;
                }
            }
        }

        return ans;
    }
};