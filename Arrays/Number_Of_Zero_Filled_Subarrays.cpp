// LEETCODE - 2348

// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        int s = 0, e = 0, zeroes = 0;
        long long subArrays = 0;
        while (e < n){
            if (nums[e] == 0) zeroes++;
            int len = e - s + 1;
            if (zeroes == len){
                subArrays += len;
                e++;
            }else {
                s = e + 1;
                e = s;
                zeroes = 0;
            }
        }
        return subArrays;
    }
};