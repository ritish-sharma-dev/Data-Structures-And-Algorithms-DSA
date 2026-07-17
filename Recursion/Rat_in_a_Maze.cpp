// LEETCODE -  Rat in a Maze Problem



class Solution{
    public:
    void f(int i, int j, vector<vector<int>> &grid, string &s, vector<string> &ans){
        if (i == grid.size()-1 && j == grid.size()-1){
            ans.push_back(s);
            return;
        }
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size()) return;
        if (grid[i][j] == 0 || grid[i][j] == -1) return;

        grid[i][j] = -1;
        f(i+1, j, grid, s += "D", ans);
        s.pop_back();
        f(i-1, j, grid, s += "U", ans);
        s.pop_back();
        f(i, j+1, grid, s += "R", ans);
        s.pop_back();
        f(i, j-1, grid, s += "L", ans);
        s.pop_back();
        grid[i][j] = 1;
    }


    vector<string> findPath(vector<vector<int> > &grid) {
        int n = grid.size();
        if (grid[0][0] == 0 || grid[n-1][n-1] == 0) return {};
        vector <string> ans;
        string s = "";
        f(0, 0, grid, s, ans);
        return ans;
    }
};