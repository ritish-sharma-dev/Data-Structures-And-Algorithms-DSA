// LEETCODE 547. Number of Provinces

class Solution {

    // n = no of cities
    // TC : O(n^2)
    // AS : O(n)

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> vis(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++){
            if (!vis[i]){
                provinces++;
                traverse(i, isConnected, vis);
            }
        }

        return provinces;
    }

    void traverse(int s, vector<vector<int>>& isConnected, vector<int> &vis){
        queue<int> q;
        q.push(s);
        vis[s] = 1;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            for (int i = 0; i < isConnected[curr].size(); i++){
                if (isConnected[curr][i] && !vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }

    }
};