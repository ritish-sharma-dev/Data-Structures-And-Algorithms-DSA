// LEETCODE - 349. Intersection of Two Arrays

// TC : O(n + m) where n is the size of nums1 and m is the size of nums2
// AS : O(n) where n is the size of nums1
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        unordered_map <int, int> mp;

        for (int x : nums1){
            mp[x]++;
        }

        for (int x : nums2){
            if (mp.find(x) != mp.end()){
                ans.push_back(x);
                mp.erase(x);
            }
        }

        return ans;
    }
};