// LEETCODE - 2110


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        int s = 0, e = 0;
        long long smoothDescentPeriods = 0;
        while (e < n){
            if (e - s + 1 != 1 && prices[e-1]-1 != prices[e]){
                s = e;
            }
            smoothDescentPeriods += e - s + 1;
            e++;
        }
        return smoothDescentPeriods;
    }
};