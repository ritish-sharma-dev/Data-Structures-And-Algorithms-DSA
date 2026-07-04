// Leetcode Problem: 45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        // TC : O(n)
        // AS : O(1)
        int n = nums.size();
        int jumps = 0;
        int s = 0, e = 0;
        while(e < n-1){
            int maxReach = 0;
            for (int i=s; i<=e; i++){
                maxReach = max(maxReach, i + nums[i]);
            }
            s = e + 1;
            e = maxReach;
            jumps += 1;
        }
        return jumps;
    }
};