class Solution {

    // V = total vertices, E = total edges
    // TC : O(V + E)
    // SC : O(V + E)
    // AS : O(V + E)

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for (auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            if (curr == destination) return true;

            for (auto neighbour : adj[curr]){
                if (!vis[neighbour]){
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }
            }
        }

        return false;
    }
};