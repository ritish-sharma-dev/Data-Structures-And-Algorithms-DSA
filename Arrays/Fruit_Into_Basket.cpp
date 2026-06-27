// LEETCODE - 904


// TC : O(n)
// AS : O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> mp;
        int maxFruits = 0;
        int s = 0;
        int e = 0;
        while (e < n) {
            mp[fruits[e]]++;
            while (mp.size() > 2) {
                mp[fruits[s]]--;
                if (mp[fruits[s]] == 0) mp.erase(fruits[s]);
                s++;
            }
            maxFruits = max(maxFruits, e - s + 1);
            e++;
        }
        return maxFruits;
    }
};