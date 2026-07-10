// LEETCODE 1470. Shuffle the Array


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // x is length of nums
        // TC : O(x/2) = O(x)
        // AS : O(x)
        vector<int> ans;

        int i = 0, j = n;

        while (j < n*2){
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
        }

        return ans;
    }
};