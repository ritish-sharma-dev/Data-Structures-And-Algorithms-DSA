class Solution {

    // TC : O(n^2)
    // SC : O(n)

public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n + 1);

        for (int i = 1; i < n; i++){
            int u = i, v = i + 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int> ans(n, 0);

        for (int i = 1; i <= n; i++){
            vector<int> vis(n + 1, 0);
            bfs(i, adj, vis, ans);
        }

        return ans;
    }

    void bfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans){
        queue<pair<int, int>> q;
        q.push({ i, 0 });
        vis[i] = 1;

        while (!q.empty()){
            int curr = q.front().first;
            int dist = q.front().second;
            q.pop();

            for (auto neighbour : adj[curr]){
                if (vis[neighbour] == 0){
                    q.push({ neighbour, dist + 1 });
                    vis[neighbour] = 1;
                    ans[dist] += 1;
                }
            }
        }
    }
};