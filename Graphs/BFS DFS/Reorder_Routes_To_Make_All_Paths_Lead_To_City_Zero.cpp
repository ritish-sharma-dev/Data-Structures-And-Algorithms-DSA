class Solution {

    // V = no of cities , E = no of roads
    // TC : O(V + E)
    // SC : O(V + E)

public:
    using VP = vector<pair<int, int>>;

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<VP> adj(n);

        for (auto connection : connections){
            int u = connection[0];
            int v = connection[1];
            adj[u].push_back({ v, 1 });
            adj[v].push_back({ u, 0 });
        }

        vector<int> vis(n, 0);

        int cnt = 0;
        dfs(adj, 0, vis, cnt);

        return cnt;
    }

    void dfs(vector<VP> &adj, int city, vector<int> &vis, int &cnt){
        vis[city] = 1;

        for (auto container : adj[city]){
            int neighbour = container.first, real = container.second;

            if (!vis[neighbour]){
                if (real == 1) cnt++;
                dfs(adj, neighbour, vis, cnt);
            }
        }
    }
};