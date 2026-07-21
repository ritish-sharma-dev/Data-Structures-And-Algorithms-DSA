// LEETCODE - 491



// TLE
class Solution {
public:
    bool find(vector<int> &v, vector<vector<int>> &ans){
        for (auto x : ans){
            if (x == v) return true;
        }
        return false;
    }

    void f(int i, vector<int> &nums, vector<int> &v, vector<vector<int>> &ans){
        int n = nums.size();
        
        if (v.size() >= 2){
            if (!find(v, ans)) ans.push_back(v);
        }

        if (i >= n) return;

        for (int j = i; j < n; j++){
            if (v.size() == 0 || nums[j] >= v[v.size()-1]) v.push_back(nums[j]);
            else continue;
            f(j+1, nums, v, ans);
            v.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;

        f(0, nums, v, ans);

        return ans;
    }
};






class Solution {
public:
    void f(int i, vector<int> &nums, vector<int> &v, set<vector<int>> &ans){
        int n = nums.size();
        
        if (v.size() >= 2){
            ans.insert(v);
        }

        if (i >= n) return;

        for (int j = i; j < n; j++){
            if (v.size() == 0 || nums[j] >= v[v.size()-1]) v.push_back(nums[j]);
            else continue;
            f(j+1, nums, v, ans);
            v.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> v;

        f(0, nums, v, ans);

        return {ans.begin(), ans.end()};
    }
};