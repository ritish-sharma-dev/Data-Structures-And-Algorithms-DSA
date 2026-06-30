// TC : O(n)
// SC : O(1)
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;
        int sStart = 0;
        int sEnd = 0;
        for (int i=0; i<n; i++){
            if (sum == 0) sStart = i;
            sum += nums[i];
            if (sum > maxSum){
                maxSum = sum;
                sEnd = i;
            }
            if (sum < 0) sum = 0;
        }
        return {sStart, sEnd};
    }
};