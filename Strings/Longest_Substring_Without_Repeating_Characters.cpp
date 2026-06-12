LEETCODE - 3. Longest Substring Without Repeating Characters

// TC : O(n)
// AS : O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        if (str.empty()) return 0;
        int s = 0;
        int e = 0;
        int maxLenOfLongestSubstring = 1;
        unordered_map <char,int> mp;
        mp[str[e]]++;
        while (e < n){
            if (mp[str[e]] == 1){
                maxLenOfLongestSubstring = max(maxLenOfLongestSubstring, e - s + 1);
                e++;
                if (e < n) mp[str[e]]++;
            }else if (mp[str[e]] > 1){
                mp[str[s]]--;
                s++;
            }
        }
        return maxLenOfLongestSubstring;
    }
};



class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        // TC : O(n)
        // AS : O(1)
        int n = str.length();
        if (str.empty()) return 0;
        int s = 0;
        int e = 0;
        int maxLenOfLongestSubstring = 1;
        vector <int> freq(128, 0);
        freq[str[e]]++;
        while (e < n){
            if (freq[str[e]] == 1){
                maxLenOfLongestSubstring = max(maxLenOfLongestSubstring, e - s + 1);
                e++;
                if (e < n) freq[str[e]]++;
            }else if (freq[str[e]] > 1){
                freq[str[s]]--;
                s++;
            }
        }
        return maxLenOfLongestSubstring;
    }
};