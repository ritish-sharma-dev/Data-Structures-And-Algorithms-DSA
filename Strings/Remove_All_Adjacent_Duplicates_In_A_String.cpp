// LEETCODE - 1047. Remove All Adjacent Duplicates In String


// TC  : O(n) where n is the size of string s
// AS  : O(n) where n is the size of string s
class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        string ans = "";

        stack <char> st;
        int i = 0;
        while (i < n){
            if (!st.empty() && st.top() == s[i]){
                st.pop();
            }else {
                st.push(s[i]);
            }
            i++;
        }

        while (!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};