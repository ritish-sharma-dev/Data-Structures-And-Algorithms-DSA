// LEETCODE 78. Subsets



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // TC : O(2^n * n)
        // SC : O(2^n * n)
        int n = nums.size();

        vector <vector<int>> ans;

        int subsets = 1 << n;

        for (int i = 0; i < subsets; i++){
            vector<int> v;
            for (int j = 0; j < n; j++){
                if (i & (1 << j)) v.push_back(nums[j]);
            }
            ans.push_back(v);
        }

        return ans;
    }
};


// USING RECURSION
// TC : O(2^n * n)
// SC : O(2^n * n)
class Solution {
public:
    void findSubSequences(int i, vector <int> &nums,vector <int> &s, vector<vector<int>> &ans ){
        if (i >= nums.size()){
            ans.push_back(s);
            return;
        }
        s.push_back(nums[i]);
        findSubSequences(i+1, nums, s, ans);
        s.pop_back();
        findSubSequences(i+1, nums, s, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        findSubSequences(0, nums, s, ans);
        return ans;
    }
};