// LEETCODE - 4010




class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long maxStrength = LLONG_MIN;

        for (int i = 0; i < n-1; i++){
            for (int j = i+1; j < n; j++){
                long long x = 1LL * nums[i] * nums[j];
                long long y = gcd(nums[i], nums[j]);
                long long strength = x / (y * y);
                maxStrength = max(maxStrength, strength);
            }
        }

        return maxStrength;
    }
};