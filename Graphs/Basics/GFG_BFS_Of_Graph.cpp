class Solution {

    // V = no of vertices, E = no of edges
    // TC : O(V + E) 
    // AS : O(v)
    // SC : O(v)

  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        
        vector<int> ans;
        
        vector<int> vis(n, 0);
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            
            ans.push_back(curr);
            
            for (int i = 0; i < adj[curr].size(); i++){
                int neighbour = adj[curr][i];
                if (vis[neighbour] == 0){
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }
            }
        }
        
        return ans;
    }
};