LEETCODE : 55. Jump Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // TC : O(n)
        // AS : O(1)
        int n = nums.size();
        int maxReach = 0;
        for (int i=0; i<n; i++){
            if (i > maxReach) return false;

            if (i + nums[i] > maxReach){
                maxReach = i + nums[i];
            }

        }

        return true;
    }
};