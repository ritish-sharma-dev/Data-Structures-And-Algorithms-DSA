// LEETCODE - 713

// OPTIMAL APPROACH
// TC : O(2n) = O(n)
// AS : O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int n = nums.size();

        int s = 0, e = 0;
        long long product = 1, subArrays = 0;

        product *= nums[e];

        while (e < n){
            if (product < k){
                subArrays += e - s + 1;
                e++;
                if (e < n) product *= nums[e];
            }else {
                product /= nums[s];
                s++;
                if (s > e) {
                    e = s;
                    product *= nums[e];
                }
            }
        }
        return subArrays;
    }
};

// OPTIMAL APPROACH
// TC : O(2n) = O(n)
// AS : O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int n = nums.size();
        int s = 0, e = 0;
        long long product = 1, subArrays = 0;

        while (e < n){
            product *= nums[e];

            while (s <= e && product >= k){
                product /= nums[s];
                s++;
            }

            subArrays += e - s + 1;
            e++;
        }
        return subArrays;
    }
};