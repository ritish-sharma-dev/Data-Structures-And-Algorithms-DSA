// LEETCODE : 2460. Apply Operations to an Array


// TC : O(n)  
// SC : O(1)
class Solution {
public:
    void moveZeroesToEnd(vector<int> &nums){
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n){
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }

    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while (i < n-1){
            if (nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
            i++;
        }

        moveZeroesToEnd(nums);

        return nums;
    }
};