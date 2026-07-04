// LEETCODE : 3979. Maximum Valid Pair Sum


class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxArr(n);
        int maxVal = 0;
        for (int i=n-1; i>=0; i--){
            if (nums[i] > maxVal) {
                maxVal = nums[i];
            }
            maxArr[i] = maxVal;
        }

        int maxValue = 0;
        int i = 0;
        int j = k + i;
        while (j < n){
            maxValue = max(maxValue, nums[i] +  maxArr[j]);
            i++;
            j++;
        }

        return maxValue;
    }
};