// LEETCODE - 4006


class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.length();

        int i = 0;
        int cnt = 0;

        int cntOf0 = 0, cntOf1 = 0;
        
        while (i < n){
            (s[i] == '0') ? cntOf0++ : cntOf1++;
            
            if (abs(cntOf0 - cntOf1) <= 1){
                cnt++;
            }
            i++;
        }

        return cnt;
    }
};