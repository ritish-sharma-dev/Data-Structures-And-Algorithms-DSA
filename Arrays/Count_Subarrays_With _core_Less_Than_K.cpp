// LEETCODE - 2302


// OPTIMAL APPROACH
// TC : O(2n) = O(n)
// AS : O(1)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int s = 0, e = 0, len = 0;
        long long sum = 0, score = 0, subArrays = 0;

        while (e < n){
            sum += nums[e];
            len = e - s + 1;
            score = sum * len;
            
            while (score >= k){
                sum -= nums[s];
                s++, len--;
                score = sum * len;
            }

            subArrays += len;
            e++;
        }
        return subArrays;
    }
};