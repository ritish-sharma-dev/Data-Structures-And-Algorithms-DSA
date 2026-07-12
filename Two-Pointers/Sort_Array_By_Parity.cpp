// LEETCODE - 905


// BRUTE FORCE APPROACH
// TC : O(2n) = O(n)
// AS : O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> ans(n, 0);

        int i = 0;
        for (int x : nums){
            if (x % 2 == 0) ans[i++] = x;
        }

        for (int y : nums){
            if (y % 2 != 0) ans[i++] = y;
        }

        return ans;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        while (i < n){
            if (nums[i] % 2 == 0) swap(nums[i], nums[j++]);
            i++;
        }

        return nums;
    }
};