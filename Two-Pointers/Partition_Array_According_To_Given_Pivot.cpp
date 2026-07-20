// LEETCODE - 2161



// TC : O(3n) = O(n)
// SC : O(n) 
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector <int> ans;

        for (int x : nums){
            if (x < pivot) ans.push_back(x);
        }

        for (int x : nums){
            if (x == pivot) ans.push_back(x);
        }

        for (int x : nums){
            if (x > pivot) ans.push_back(x);
        }

        return ans;
    }
};