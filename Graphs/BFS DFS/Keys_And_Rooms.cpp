class Solution {

    // n = no of rooms, k = total keys
    // TC : O(n + k)
    // SC : O(n)
    // AS : O(n)

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty()){
            int curr = q.front();
            q.pop();

            for (auto key : rooms[curr]){
                if (!vis[key]){
                    q.push(key);
                    vis[key] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++){
            if (vis[i] == 0) return false;
        }

        return true;
    }
};