// LEETCODE - 557

class Solution {
public:
    string reverseWords(string s) {
        // TC : O(n)
        // AS : O(n)

        int n = s.length();
        stack <char> st;
        string ans = "";

        int i = 0;
        while (i < n){
            while (i < n && s[i] != ' '){
                st.push(s[i]);
                i++;
            }

            while (!st.empty()){
                ans += st.top();
                st.pop();
            }
            if (i < n) ans += ' ';
            i++;
        }

        return ans;
    }
};