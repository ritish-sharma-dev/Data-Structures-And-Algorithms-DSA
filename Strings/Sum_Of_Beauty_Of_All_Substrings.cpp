// LEETCODE - 1781

// BRUTE FORCE APPROACH
// TC : O(n^3)
// AS : O(26)
class Solution {
public:
    int beautySum(string s) {
        int n = s.length();

        int sum = 0;

        for (int i=0; i<n; i++){
            vector<int> freq(26, 0);
            for (int j=i; j<n; j++){
                freq[s[j] - 'a']++;
                int MFF = INT_MIN;
                int LFF = INT_MAX;
                for (int k=i; k<=j; k++){
                    if (freq[s[k] - 'a'] > MFF) MFF = freq[s[k] - 'a'];
                    if (freq[s[k] - 'a'] < LFF) LFF = freq[s[k] - 'a'];
                }
                int beauty = MFF - LFF;
                sum += beauty;
            }
        }
        return sum;
    }
};


// OPTIMIZED APPROACH
// TC : O(n^2)
// AS : O(26)
class Solution {
public:
    int beautySum(string s) {
        int n = s.length();

        int sum = 0;

        for (int i=0; i<n; i++){
            vector<int> freq(26, 0);
            for (int j=i; j<n; j++){
                freq[s[j] - 'a']++;
                int MFF = INT_MIN;
                int LFF = INT_MAX;
                for (int k=0; k<26; k++){
                    if (freq[k] != 0 && freq[k] > MFF) MFF = freq[k];
                    if (freq[k] != 0 && freq[k] < LFF) LFF = freq[k];
                }
                int beauty = MFF - LFF;
                sum += beauty;
            }
        }
        return sum;
    }
};