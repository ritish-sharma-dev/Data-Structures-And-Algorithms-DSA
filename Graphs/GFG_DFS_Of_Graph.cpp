class Solution {

    // V = no of vertices, E = no of edges
    // TC : O(V + E)
    // AS : O(V)


  public:
    void dfsTraversal(int source, vector<vector<int>>& adj, vector<int> &vis,
    vector<int> &ans){
        vis[source] = 1;
        
        ans.push_back(source);
        
        for (int neighbour : adj[source]){
            if (!vis[neighbour]){
                dfsTraversal(neighbour, adj, vis, ans);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        
        vector<int> ans;
        
        vector<int> vis(V, 0);
        
        dfsTraversal(0, adj, vis, ans);
        
        return ans;
    }
};