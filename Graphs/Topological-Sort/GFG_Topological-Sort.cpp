class Solution {
    
    // DFS
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



class Solution {

    // BFS
    // TC : O(V + E)
    // SC : O(V + E)
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        vector<int> indegree(V, 0);
        
        for (auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++){
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            
            ans.push_back(curr);
            
            for (auto neighbour : adj[curr]){
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) q.push(neighbour);
            }
        }
        
        return ans;
    }
};