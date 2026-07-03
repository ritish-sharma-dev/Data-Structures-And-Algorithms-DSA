// LEETCODE : 76. Minimum Window Substring

class Solution {
public:
    bool getAllChar(vector<int> &freq){
        for (int i=0; i<256; i++){
            if (freq[i] > 0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        // TC : O(n + m)
        // AS : O(1)
        int m = s.length();
        int n = t.length();

        vector<int> freq(256, 0);
        for (char x : t){
            freq[x]++;
        }

        int ss = -1;
        int se = -1;
        int minLen = INT_MAX;

        int l = 0;
        int r = 0;
        while (r < m){
            freq[s[r]]--;

            while (getAllChar(freq)){
                if (r - l + 1 < minLen){
                    ss = l;
                    se = r;
                    minLen = r - l + 1;
                }
                freq[s[l]]++;
                l++;
            }
            r++;
        }
        return (ss == -1 && se == -1) ? "" : s.substr(ss, se - ss + 1);
    }
};