// LEETCODE 56. Merge Intervals

// TC : O(nlogn) + O(n) = O(nlogn)
// AS : O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for (int i=0; i<n; i++){
            if (intervals[i][0] > ans[ans.size()-1][1]){
                ans.push_back(intervals[i]);
            }else {
                ans[ans.size()-1][1] = max(intervals[i][1],ans[ans.size()-1][1]);
            }
        }

        return ans;
    }
};