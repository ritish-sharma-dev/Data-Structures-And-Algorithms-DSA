// Leetcode : 2360. Longest Cycle in a Graph


class Solution {

    // n = no of vertices or nodes
    // TC : O(n)
    // SC : O(n)

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int longestLenOfCycle = -1;

        vector<int> vis(n, 0);
        vector<pair<int, int>> path(n);

        int len = 0;
        for (int i = 0; i < n; i++){
            if (vis[i] == 0){
                dfs(i, len, edges, vis, path, longestLenOfCycle);
            }
        }

        return longestLenOfCycle;
    }

    void dfs(int i, int &len, vector<int> &edges, vector<int> &vis, vector<pair<int,int>> &path, int &longestLenOfCycle){
        len++;
        vis[i] = 1;
        path[i] = {1, len};

        int neighbour = edges[i];
        if (neighbour != -1){
            if (vis[neighbour] == 0){
                dfs(neighbour, len, edges, vis, path, longestLenOfCycle);
            }else if (path[neighbour].first == 1) {
                int cycleLen = len - path[neighbour].second + 1;
                longestLenOfCycle = max(longestLenOfCycle, cycleLen);
            }
        }

        len--;
        path[i] = {0, 0};
    }
};