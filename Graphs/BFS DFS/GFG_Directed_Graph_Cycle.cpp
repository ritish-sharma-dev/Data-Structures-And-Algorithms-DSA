class Solution {

    // V = no of nodes or vertices, E = no of edges
    // TC : O(V + E)
    // SC : O(V + E)

  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        vector<int> path(V, 0);
        
        for (int i = 0; i < V; i++){
            if (vis[i] == 0 && dfs(i, adj, vis, path)) return true;
        }
        
        return false;
    }
    
    bool dfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path){
        vis[i] = 1;
        path[i] = 1;
        
        for (auto neighbour : adj[i]){
            if (vis[neighbour] == 0){
                if (dfs(neighbour, adj, vis, path)) return true;
            }else {
                if (path[neighbour] == 1) return true;
            }
        }
        path[i] = 0;
        
        return false;
    }
};