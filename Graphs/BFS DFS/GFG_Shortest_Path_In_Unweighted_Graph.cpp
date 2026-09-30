class Solution {

    // TC : O(V + E)
    // SC : O(V + E)

  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adj(V);
        
        for (auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        
        queue<pair<int, int>> q;
        q.push( {src, 0} );
        vis[src] = 1;
        
        while (!q.empty()){
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            
            if (node == dest) return distance;
            
            for (auto neighbour : adj[node]){
                if (vis[neighbour] == 0) {
                    q.push({ neighbour, distance + 1 });
                    vis[neighbour] = 1;
                }
            }
        }
        
        return -1;
    }
};
