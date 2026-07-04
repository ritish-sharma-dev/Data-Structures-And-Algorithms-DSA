// Leetcode Problem: 3978. Unique Middle Element

// Brute Force Approach
// TC : O(n)
// AS : O(n)
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;

        for (int x : nums){
            mp[x]++;
        }

        int middleElement = nums[n/2];

        return mp[middleElement] == 1 ? true : false;
    }
};



// Optimized Approach
// TC : O(n)
// AS : O(1)
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int middle = nums[n/2];

        int cnt = 0;
        for (int x : nums){
            if (x == middle) cnt++;
        }

        return cnt == 1 ? true : false;
    }
};