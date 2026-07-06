//LEETCODE 57. Insert Interval 

// TC : O(n)
// AS : O(1)
// SC : O(n+1) = O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> ans;

        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);

        while (i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};



// TC : O(n)
// AS : O(1)
// SC : O(n+1) = O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> ans;

        bool newIntervalAdded = false;

        int i = 0;
        while (i < n){
            if (newInterval[0] < intervals[i][0] || newInterval[1] < intervals[i][0]){
                ans.push_back(newInterval);
                newIntervalAdded = true;
                break;
            }else if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1] ||
                      newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                ans.push_back({ min(intervals[i][0], newInterval[0]), max(newInterval[1], intervals[i][1]) });
                newIntervalAdded = true;
                break;
            }
            ans.push_back(intervals[i]);
            i++;
        }

        while (i < n){
            if (intervals[i][0] > ans[ans.size()-1][1]){
                ans.push_back(intervals[i]);
            }else {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
            i++;
        }

        if (!newIntervalAdded) ans.push_back(newInterval);

        return ans;
    }
};