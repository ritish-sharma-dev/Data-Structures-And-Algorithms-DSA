class Solution {
    
    // V = no of vertices, E = no of edges
    // TC : O(V + E)
    // SC : O(V + E)
    
  private:
    void bfs(int i, vector<vector<int>> &adj, vector<int> &vis){
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            
            for (auto neighbour : adj[curr]){
                if (!vis[neighbour]){
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }
            }
        }
    }
  
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        
        int cnt = 0;
        for (int i = 0; i < V; i++){
            if (vis[i] == 0){
                bfs(i, adj, vis);
                cnt++;
            }
        }
        
        return cnt;
    }
};