// LEETCODE - 1493


// OPTIMAL APPROACH
// TC : O(2n) = O(n)
// AS : O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = 0, longestSubarray = 0, subarray = 0, zeroes = 0;
        
        while (e < n){
            if (nums[e] == 0) zeroes++;

            while (zeroes > 1){
                if (nums[s] == 0) zeroes--;
                s++;
            }

            subarray = e - s;
            longestSubarray = max(longestSubarray, subarray);
            e++;
        }
        return longestSubarray;
    }
};