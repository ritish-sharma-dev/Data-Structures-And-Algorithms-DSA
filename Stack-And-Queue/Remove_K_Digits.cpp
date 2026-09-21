// LEETCODE - 402. Remove K Digits


// TC : O(n)
// AS : O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if (n == k) return "0";
        stack <char> s;
        for (int i=0; i<n; i++){
            while (!s.empty() && k>0 && s.top() > num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while (k>0){
            s.pop();
            k--;
        }
        string res = "";
        while (!s.empty()){
            res += s.top();
            s.pop();
        }
        while (res.size() != 0 && res[res.size()-1] == '0'){
            res.pop_back();
        }
        if (res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};