// LEETCODE - 3974


// TC : O(nlogn + k)
// AS : O(1)
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i=0;
        long long sum = 0;
        while (i < k){
            if (mul > 0) sum += (1LL * nums[n-i-1] * mul);
            else sum += nums[n-i-1];
            mul--;
            i++;
        }
        return sum;
    }
};