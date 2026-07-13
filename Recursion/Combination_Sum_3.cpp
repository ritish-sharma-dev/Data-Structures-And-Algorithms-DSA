// LEETCODE - 216




class Solution {
public:
    void f(int i, vector<int> &nums, vector<int> &s, vector<vector<int>> &ans){
        ans.push_back(s);
        for (int j=i; j<nums.size(); j++){
            if (j > i && nums[j] == nums[j-1]) continue;
            s.push_back(nums[j]);
            f(j+1, nums, s, ans);
            s.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> s;

        f(0, nums, s, ans);
        return ans;
    }
};