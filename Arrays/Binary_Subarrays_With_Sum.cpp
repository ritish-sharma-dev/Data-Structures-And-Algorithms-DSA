// LEETCODE - 930

// BRUTE FORCE APPROACH
// TC : O(n^3)
// SC : O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                int sum = 0;
                for (int k=i; k<=j; k++){
                    sum += nums[k];
                }

                if (sum == goal){
                    count++;
                }
            }
        }
        return count;
    }
};


// BETTER APPROACH
// TC : O(n^2)
// SC : O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=i; j<n; j++){
                sum += nums[j];
                if (sum == goal) count++;
            }
        }
        return count;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
class Solution {
public:
    int findingSubarrays(vector<int> &nums, int goal){
        if (goal < 0) return 0;
        int n = nums.size();
        int s = 0;
        int e = 0;
        int sum = 0;
        int count = 0;
        while (e < n){
            sum += nums[e];
            while (sum > goal){
                sum -= nums[s];
                s++;
            }
            count += e - s + 1;
            e++;
        }
        return count;
    }



    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findingSubarrays(nums, goal) - findingSubarrays(nums, goal - 1);
    }
};