// LEETCODE - 26

// TC : O(n)
// AS : O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n){
            if (nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};