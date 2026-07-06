// GFG 

// TC : O(nlogn) + O(n) ~ O(nlogn)
// AS : O(1)
class Solution {
  public:
    int solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        
        int totalWaitingTime = 0;
        int waitingTime = 0;
        for (int i=0; i<n; i++){
            totalWaitingTime += waitingTime;
            waitingTime += bt[i];
        }
        return (int)totalWaitingTime/n;
    }
};