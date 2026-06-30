// LEETCODE - 53


// BRUTE FORCE APPROACH
// TC : O(n^3)
// SC : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSubArraySum = INT_MIN;

        for (int i=0; i<n; i++){
            int subArrayStart = i;
            for (int j=i; j<n; j++){
                int subArrayEnd = j;
                int subArraySum = 0;
                for (int k=subArrayStart; k<=subArrayEnd; k++){
                    subArraySum += nums[k];
                }

                if (subArraySum > maxSubArraySum){
                    maxSubArraySum = subArraySum;
                }
            }
        }

        return maxSubArraySum;
    }
};



// BETTER APPROACH
// TC : O(n^2)
// SC : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSubArraySum = INT_MIN;

        for (int i=0; i<n; i++){
            int subArrayStart = i;
            int subArraySum = 0;
            for (int j=i; j<n; j++){
                int subArrayEnd = j;
                subArraySum += nums[j];

                if (subArraySum > maxSubArraySum){
                    maxSubArraySum = subArraySum;
                }
            }
        }

        return maxSubArraySum;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// SC : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN, sum = 0;
        for (int i=0; i<n; i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
};