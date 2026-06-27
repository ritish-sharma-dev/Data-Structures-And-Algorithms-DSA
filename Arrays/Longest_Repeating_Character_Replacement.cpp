// LEETCODE - 424


// TC : O(n^2)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int maxFreq(vector<int> &freq){
        int max = INT_MIN;
        int n = freq.size();
        for (int i=0; i<n; i++){
            if (freq[i] > max){
                max = freq[i];
            }
        }
        return max;
    }

    int characterReplacement(string s, int k) {
        int n = s.length();
        int longestSubSize = 0;

        for (int i=0; i<n; i++){
            vector <int> freq(26, 0);
            for (int j=i; j<n; j++){
                freq[s[j] - 'A'] += 1;
                int mFreq = maxFreq(freq);
                int noOfCharChange = j - i + 1 - mFreq;
                if (noOfCharChange <= k){
                    longestSubSize = max(longestSubSize, j - i + 1);
                }
            }
        }

        return longestSubSize;
    }
};


// TC : O(2n) = O(n)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int maxFreq(vector<int>& freq) {
        int max = INT_MIN;
        int n = freq.size();
        for (int i = 0; i < n; i++) {
            if (freq[i] > max) {
                max = freq[i];
            }
        }
        return max;
    }

    int characterReplacement(string s, int k) {
        int n = s.length();
        int longestSubSize = 0;
        vector<int> freq(26, 0);

        int start = 0;
        int end = 0;
        freq[s[end] - 'A'] += 1;
        while (end < n) {
            int mFreq = maxFreq(freq);
            int noOfCharChange = end - start + 1 - mFreq;
            if (noOfCharChange <= k) {
                longestSubSize = max(longestSubSize, end - start + 1);
                if (++end < n) freq[s[end] - 'A'] += 1;
            }else {
                freq[s[start++] - 'A'] -= 1;
            }
        }
        return longestSubSize;
    }
};