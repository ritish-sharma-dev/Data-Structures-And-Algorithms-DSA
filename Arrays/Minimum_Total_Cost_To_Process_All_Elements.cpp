// LEETCODE - 3987

// BRUTE FORCE
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int availResources = k;
        int costing = 0;
        int cost = 1;
        int MOD = 1e9 + 7;

        int i = 0;
        while (i < nums.size()){
            
            while (availResources < nums[i]){
                availResources += k;
                costing = (costing + cost) % MOD;
                cost++;
            }

            availResources -= nums[i];
            i++;
        }

        return costing;
    }
};

// OPTIMAL APPROACH
// TC : O(n)
// SC : O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        int availResources = k;
        int costing = 0;
        int cost = 1;
        int MOD = 1e9 + 7;

        int i = 0;
        while (i < nums.size()) {

            if (availResources < nums[i]) {
                long long x = abs(ceil((nums[i] - availResources) / (double)k));
                availResources = availResources + (k * x);

                long long term1 = (x * cost) % MOD;
                long long term2 = (x * (x - 1) / 2) % MOD;

                costing = (costing + term1 + term2) % MOD;
                cost = (cost + x) % MOD;
            }

            availResources -= nums[i];
            i++;
        }

        return costing;
    }
};