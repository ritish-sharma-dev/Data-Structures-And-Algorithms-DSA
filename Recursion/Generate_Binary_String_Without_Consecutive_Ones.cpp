// TUF

// TC : O(2^n * n)
// AS : O(n)
class Solution {
public:
    bool checkConsecutiveOnes(string &s){
        int i = 0;
        int j = 1;
        while (j < s.length()){
            if (s[i] == '1' && s[j] == '1'){
                return true;
            }
            i++;
            j++;
        }
        return false;
    }

    void rev(string &s){
        int i = 0;
        int j = s.length() - 1;
        while (i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;

        int subsets = 1 << n;

        for (int i=0; i<subsets; i++){
            string s = "";
            for (int j=0; j<n; j++){
                if (i & 1 << j) s += "1";
                else s += "0";
            }
            bool consecutiveOnes = checkConsecutiveOnes(s);
            if (!consecutiveOnes){
                rev(s);
                ans.push_back(s);
            }
        }

        return ans;
    }
};


class Solution {
public:
    void f(int n, string s, vector<string> &ans) {
        if (s.length() == n) {
            ans.push_back(s);
            return; 
        } 
                                
        f(n, s + "0", ans);
                                            
        if (s.empty() || s.back() != '1') {
            f(n, s + "1", ans);
        }
}

    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        string s = "";
        f(n, s, ans);
        return ans;
    }
};


