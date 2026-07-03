// LEETCODE - 5

// BRUTE FORCE APPROACH
// TLE
// TC : O(n^3)
// AS : O(n)
class Solution {
    public boolean checkPalindrome(String subStr){
        int i = 0;
        int j = subStr.length() - 1;
        while (i < j){
            if (subStr.charAt(i) != subStr.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    public String longestPalindrome(String s) {
        int n = s.length();

        String longestSub = "";

        for (int i=0; i<n; i++){
            String subStr = "";
            for (int j=i; j<n; j++){
                subStr += s.charAt(j);
                boolean isPalindrome = checkPalindrome(subStr);
                if (isPalindrome && j - i + 1 > longestSub.length()){
                    longestSub = subStr;
                }
            }
        }
        return longestSub;
    }
}

// BETTER IN SPACE - BRUTE FORCE APPROACH
// TLE
// TC : O(n^3)
// AS : O(1)
class Solution {
public:
    bool checkPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        string longestSub = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool isPalindrome = checkPalindrome(s, i, j);
                if (isPalindrome && j - i + 1 > longestSub.length()) {
                    longestSub = "";
                    for (int k = i; k <= j; k++) {
                        longestSub += s[k];
                    }
                }
            }
        }
        return longestSub;
    }
};

// OPTIMIZED APPROACH
// TC : O(n^2)
// AS : O(1)
class Solution {
public:
    void check(string &s, int start, int end, string &longPalindromicSub){
        int n = s.length();
        while (start >= 0 && end < n && s[start] == s[end]){
            if (end - start + 1 > longPalindromicSub.length()){
                longPalindromicSub = s.substr(start, end - start + 1);
            }
            start--;
            end++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();

        string longPalindromicSub = "";

        for (int i=0; i<n; i++){
            int start = i;
            int end = i;
            check(s, start, end, longPalindromicSub);

            start = i;
            end = i+1;
            check(s, start, end, longPalindromicSub);
        }

        return longPalindromicSub;
    }
};