// LEETCODE - 697


// BRUTE FORCE APPROACH
// TC : O(n^2)
// AS : O(n)
class Solution {
public:
    int findMaxFreq(unordered_map <int, int> &mp){
        int maxFreq = 0;
        for (auto x : mp){
            if (x.second > maxFreq) maxFreq = x.second;
        }
        return maxFreq;
    }

    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;

        for (int x : nums){
            mp[x]++;
        }

        int degree = findMaxFreq(mp);
        mp.clear();

        int s = 0, e = 0, minLen = INT_MAX;
        while (e < n){
            mp[nums[e]]++;
            int maxFreq = findMaxFreq(mp);

            while (maxFreq == degree){
                minLen = min(minLen, e - s + 1);
                mp.erase(nums[s]);
                s++;
                maxFreq = findMaxFreq(mp);
            }
            e++;
        }
        return minLen;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(n)
class Solution {
public:
    int findMaxFreq(unordered_map <int, int> &mp){
        int maxFreq = 0;
        for (auto x : mp){
            if (x.second > maxFreq) maxFreq = x.second;
        }
        return maxFreq;
    }

    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int, int> mp;

        for (int x : nums){
            mp[x]++;
        }

        int degree = findMaxFreq(mp);
        mp.clear();

        int s = 0, e = 0, minLen = INT_MAX;
        while (e < n){
            mp[nums[e]]++;

            while (mp[nums[e]] == degree){
                minLen = min(minLen, e - s + 1);
                mp.erase(nums[s]);
                s++;
            }

            e++;
        }
        return minLen;
    }
};