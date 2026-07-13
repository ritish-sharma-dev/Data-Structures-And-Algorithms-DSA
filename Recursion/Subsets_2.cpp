// LEETCODE - 90


class Solution {
public:
    void f(int i, vector<int>&nums, vector<int> &s, set<vector<int>> &x){
        if (i >= nums.size()){
            x.insert(s);
            return;
        }

        s.push_back(nums[i]);
        f(i+1, nums, s, x);

        s.pop_back();
        f(i+1, nums, s, x);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set <vector<int>> x;
        vector<int> s;

        f(0, nums, s, x);

        vector<vector<int>> ans;
        for (auto i : x){
            ans.push_back(i);
        }
        return ans;
    }
};






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