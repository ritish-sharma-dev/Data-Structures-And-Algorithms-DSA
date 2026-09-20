class Solution {

    // V = no of nodes or vertices, E = no of edges
    // BFS approach to check if a graph is bipartite or not
    // TC : O(V + E)
    // SC : O(V)

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<char> s(n, 'N');

        for (int i = 0; i < n; i++){
            if (s[i] == 'N' && !check(i, graph, s)) return false;
        }

        return true;
    }

    bool check(int i, vector<vector<int>> &graph, vector<char> &s){
        queue<int> q;
        q.push(i);
        s[i] = 'A';

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            for (auto neighbour : graph[curr]){
                if (s[neighbour] == 'N'){
                    q.push(neighbour);
                    s[neighbour] = s[curr] == 'A' ? 'B' : 'A';
                }else {
                    char mySet = s[curr];
                    char neighbourSet = s[neighbour];
                    if (mySet == neighbourSet) return false;
                }
            }
        }

        return true;
    }
};



class Solution {

    // V = no of nodes or vertices, E = no of edges
    // DFS Traversal
    // TC : O(V + E)
    // SC : O(V)

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<char> s(n, 'N');

        for (int i = 0; i < n; i++){
            if (s[i] == 'N' && !dfs(i, graph, s)) return false;
        }

        return true;
    }

    bool dfs(int i, vector<vector<int>> &graph, vector<char> &s){
        if (s[i] == 'N') s[i] = 'A';

        for (auto neighbour : graph[i]){
            if (s[neighbour] == 'N'){
                s[neighbour] = s[i] == 'A' ? 'B' : 'A';
                if (!dfs(neighbour, graph, s)) return false;
            }else {
                int mySet = s[i];
                char neighbourSet = s[neighbour];
                if (mySet == neighbourSet) return false;
            }
        }

        return true;
    }
};