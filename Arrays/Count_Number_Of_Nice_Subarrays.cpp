// LEETCODE - 1248


// TC : O(n^2)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int niceSubarrays = 0;

        for (int i=0; i<n; i++){
            int odd = 0;
            for (int j=i; j<n; j++){
                if (nums[j] % 2 != 0){
                    odd++;
                }
                if (odd == k) niceSubarrays++;
            }
        }
        return niceSubarrays;
    }
};



class Solution {
public:
    int findSubarrays(vector<int> &nums, int k){
        int n = nums.size();
        int s = 0, e = 0, cnt = 0, odd = 0;
        while (e < n){
            if (nums[e] % 2 != 0) odd++;
            while (odd > k){
                if (nums[s] % 2 != 0) odd--;
                s++;
            }
            cnt += e - s + 1;
            e++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return findSubarrays(nums, k) - findSubarrays(nums, k-1);
    }
};