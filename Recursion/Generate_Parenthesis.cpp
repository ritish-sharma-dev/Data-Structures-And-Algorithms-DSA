// LEETCODE - 22


class Solution {
public:
    void f(string &s, vector<string> &ans, int n, int cnt){
        if (s.length() >= n*2){
            if (cnt == 0) ans.push_back(s);
            return;
        }
        s += "(";
        f(s , ans, n, cnt + 1);
        s.pop_back();

        if (cnt > 0) {
            s += ")";
            f(s, ans, n, cnt - 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        f(s, ans, n, 0);
        return ans;
    }
};