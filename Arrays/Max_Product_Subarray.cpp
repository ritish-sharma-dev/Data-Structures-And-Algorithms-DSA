// LEETCODE - 152

// OPTIMAL APPROACH
// TC : O(2n) = O(n)
// AS : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = INT_MIN, p = 1;

        for (int i = 0; i < n; i++) {
            p *= nums[i];
            maxP = max(p, maxP);
            if (p == 0) p = 1;
        }

        p = 1;
        for (int i = n - 1; i >= 0; i--) {
            p *= nums[i];
            maxP = max(p, maxP);
            if (p == 0) p = 1;
        }

        return maxP;
    }
};
