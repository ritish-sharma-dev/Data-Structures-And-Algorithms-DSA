// LEETCODE : 2410. Maximum Matching of Players With Trainers

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // TC : O(mlogm + nlogn + m + n)
        // AS : O(1)
        int m = players.size();
        int n = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0;
        while (i < m && j < n){
            int ability = players[i];
            int capacity = trainers[j];
            if (ability <= capacity){
                i++;
            }
            j++;
        }
        return i;
    }
};