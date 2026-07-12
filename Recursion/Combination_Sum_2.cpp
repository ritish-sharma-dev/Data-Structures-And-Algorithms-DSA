// LEETCODE - 40



class Solution {
public:
    void f(int i, vector<int> &candidates, int t, vector<int> &s, vector<vector<int>> &ans){
        if (t == 0){
            ans.push_back(s);
            return;
        }

        for (int j = i; j<candidates.size(); j++){
            if (j > i && candidates[j] == candidates[j-1]) continue;
            if (candidates[j] > t) break;
            s.push_back(candidates[j]);
            f(j + 1, candidates, t - candidates[j], s, ans);
            s.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> s;
        f(0, candidates, target, s, ans);
        return ans;
    }
};