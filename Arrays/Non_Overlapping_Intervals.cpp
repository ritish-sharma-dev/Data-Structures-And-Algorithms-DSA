// LEETCODE 435. Non-overlapping Intervals


// TC : O(nlogn + n)
// AS : O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        int cnt = 0;
        int i = 0;
        int j = 1;
        while (j < n){
            if (intervals[j][0] < intervals[i][1]){
                cnt++;
                if (intervals[j][1] < intervals[i][1]) {
                    i = j; 
                }
            }else i = j;
            j++;
        }

        return cnt;
    }
};