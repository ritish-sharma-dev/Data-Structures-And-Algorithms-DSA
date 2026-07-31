// LEETCODE - 1695


// TC : O(n)
// AS : O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxScore = 0;
        int score = 0;

        unordered_map <int, int> mp;

        int i = 0;
        int j = 0;
        while (j < n){
            score += nums[j];
            mp[nums[j]]++;

            while (mp[nums[j]] > 1){
                score -= nums[i];
                mp[nums[i]]--;
                i++;
            }

            maxScore = max(maxScore, score);
            j++;
        }

        return maxScore;
    }
};