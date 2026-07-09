// LEETCODE : 125. Valid Palindrome



class Solution {
public:
    bool isPalindrome(string s) {
        // TC : O(n)
        // AS : O(n)
        int n = s.length();

        string str = "";
        for (char x : s){
            if (x >= 'A' && x <= 'Z') str += x + 32;
            if (x >= 'a' && x <= 'z' || x >= '0' && x <= '9') str += x;
        }

        int i = 0;
        int j = str.length() - 1;
        while (i < j){
            if (str[i] != str[j]) return false;
            i++, j--;
        }
        return true;
    }
};



// USING RECURSION
// TC : O(n)
// AS : O(n)
class Solution {
public:
    bool checkPalindrome(string &str, int i, int j){
        if (i >= j) return true;
        if (str[i] != str[j]) return false;
        return checkPalindrome(str, ++i, --j);
    }

    bool isPalindrome(string s) {
        int n = s.length();

        string str = "";
        for (char x : s){
            if (x >= 'A' && x <= 'Z') str += x + 32;
            if (x >= 'a' && x <= 'z' || x >= '0' && x <= '9') str += x;
        }

        return checkPalindrome(str, 0, str.length()-1);
    }
};