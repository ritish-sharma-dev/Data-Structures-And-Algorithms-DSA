// LEETCODE - 131



class Solution {
public:
    bool checkPalindrome(string &s, int i, int j){
        while (i < j){
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    void f(int i, string &s, vector<string> &pv, vector<vector<string>> &ans){
        if (i >= s.length()){
            ans.push_back(pv);
            return;
        }

        for (int j = i; j < s.length(); j++){
            if (checkPalindrome(s, i, j)){
                string str = "";
                for (int k = i; k <= j; k++){
                    str += s[k];
                }
                pv.push_back(str);
                f(j+1, s, pv, ans);
                pv.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pv;

        f(0, s, pv, ans);

        return ans;
    }
};