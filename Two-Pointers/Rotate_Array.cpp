// LEETCODE - 189


// Brute Force Approach
// TC : O(n*k) = O(n^2)
// AS : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < k; i++){
            int temp = nums[n-1];
            int j;
            for (j = n - 1; j > 0; j--){
                nums[j] = nums[j-1];
            }
            nums[j] = temp;
        }
    }
};




// TC : O(n)
// AS : O(1)
class Solution {
public:
    void reverseK(vector<int> &nums){
        int i = 0;
        int j = nums.size()-1;
        while (i < j){
            swap(nums[i++], nums[j--]);
        }
    }

    void reverse(vector<int> &nums, int i, int j){
        while (i < j) swap(nums[i++], nums[j--]);
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        int r = k % n;

        reverseK(nums);
        reverse(nums, 0, r - 1);
        reverse(nums, r, n - 1);
    }
};