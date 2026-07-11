// LEETCODE - 39


class Solution {
public:
   void combinations(int i, vector<int> &nums,  int t, vector<int> &s, vector<vector<int>> &ans){
        if (i >= nums.size()){
            if (t == 0) ans.push_back(s);
            return;
        }
        if (nums[i] <= t){
            s.push_back(nums[i]);
            combinations(i, nums, t - nums[i], s, ans);
            s.pop_back();
        }
        combinations(i+1, nums, t, s, ans);
   }
    

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> s;

        combinations(0, nums, target, s, ans);
        return ans;
    }
};