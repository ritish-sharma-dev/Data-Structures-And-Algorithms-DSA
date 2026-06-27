// LEETCODE - 992



class Solution {
public:
    int findingSubarrays(vector<int> &nums, int k){
        int n = nums.size();
        int s = 0, e = 0, cnt = 0;
        unordered_map <int, int> mp;
        while (e < n){
            mp[nums[e]]++;

            while (mp.size() > k){
                mp[nums[s]]--;
                if (mp[nums[s]] == 0) mp.erase(nums[s]);
                s++;
            }
            cnt += e - s + 1;
            e++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findingSubarrays(nums, k) - findingSubarrays(nums, k-1);
    }
};