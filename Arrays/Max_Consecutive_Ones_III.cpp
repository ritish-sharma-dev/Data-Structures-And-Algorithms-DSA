// LEETCODE - 1004


// TC : O(n^2)
// AS : O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxSubarraySize = 0;
        for (int i=0; i<n; i++){
            int zeroes = 0;
            int j;
            for (j=i; j<n; j++){
                if (nums[j] == 0){
                    zeroes++;
                }
                if (zeroes == k){
                    maxSubarraySize = max(maxSubarraySize, j - i + 1);
                }
            }

            if (i == 0 && k >= zeroes) return n;
        }
        return maxSubarraySize;
    }
};



// TC : O(2n) = O(n)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeroes = 0;
        int maxLen = 0;
        while (j < n){
            if (nums[j] == 0) zeroes++;
            if (zeroes <= k){
                maxLen = max(maxLen, j - i + 1);
                j++;
            }else {
                while (i <= j &&  zeroes > k){
                    if (nums[i] == 0){
                        zeroes--;
                    }
                    i++;
                }
                if (i <= j) maxLen = max(maxLen, j - i + 1);
                j++;
            }
        }

        return maxLen;
    }
};


// TC : O(2n) = O(n)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeroes = 0;
        int maxLen = 0;
        while (j < n) {
            if (nums[j] == 0) zeroes++;
            while (zeroes > k) {
                if (nums[i] == 0) {
                    zeroes--;
                }
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // TC : O(n)
        // AS : O(1)
        // SC : O(1)
        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeroes = 0;
        int maxLen = 0;
        while (j < n) {
            if (nums[j] == 0) zeroes++;
            if (zeroes > k) {
                if (nums[i] == 0) {
                    zeroes--;
                }
                i++;
            }
            if (zeroes <= k) maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};