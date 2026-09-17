// Note: The graph cannot have multiple component.
// BFS

class Solution {
    
  // V = no of vertices, E = no of edges
  // TC : O(V + E)
  // SC : O(V + E)
    
  private:
    bool detectCycle(vector<vector<int>> &adj, vector<int> &vis){
        queue<pair<int, int>> q;
        q.push({ 0, -1 });
        vis[0] = 1;
        
        while (!q.empty()){
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto neighbour : adj[curr]){
                if (!vis[neighbour]){
                    q.push({ neighbour, curr });
                    vis[neighbour] = 1;
                }else {
                    if (neighbour != parent) return true;
                }
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        
        return detectCycle(adj, vis);
    }
};


// Note: The graph can have multiple component.
// BFS
class Solution {
    
  // V = no of vertices, E = no of edges
  // TC : O(V + E)
  // SC : O(V + E)
    
  private:
    bool detectCycle(int src, vector<vector<int>> &adj, vector<int> &vis){
        queue<pair<int, int>> q;
        q.push({ src, -1 });
        vis[src] = 1;
        
        while (!q.empty()){
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (auto neighbour : adj[curr]){
                if (!vis[neighbour]){
                    q.push({ neighbour, curr });
                    vis[neighbour] = 1;
                }else {
                    if (neighbour != parent) return true;
                }
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++){
            if (vis[i] == 0){
                if (detectCycle(i, adj, vis)) return true;
            }
        }
        
        return false;
    }
};


// Note: The graph can have multiple component.
// DFS
class Solution {

  // V = no of vertices, E = no of edges
  // TC : O(V + E)
  // SC : O(V + E)

  private:
    bool dfs(int i, int p, vector<vector<int>> &adj, vector<int> &vis){
        vis[i] = 1;
        
        for (auto neighbour : adj[i]){
            if (vis[neighbour] == 0){
                if (dfs(neighbour, i, adj, vis)) return true;
            }else {
                if (neighbour != p) return true;
            }
        }
        
        return false;
    }
  
  
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for (auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        
        for (int i = 0; i < V; i++){
            if (vis[i] == 0 && dfs(i, -1, adj, vis)) return true;
        }
        
        return false;
    }
};