class Solution {
    
    // TC : O(V + E)
    // SC : O(V + E)
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        stack<int> s;
        
        for (int i = 0; i < V; i++){
            if (!vis[i]) dfs(i, adj, vis, s);
        }
        
        vector<int> ans;
        while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
    
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, stack<int> &s){
        vis[i] = 1;
        
        for (auto neighbour : adj[i]){
            if (!vis[neighbour]){
                dfs(neighbour, adj, vis, s);
            }
        }
        s.push(i);
    }
};