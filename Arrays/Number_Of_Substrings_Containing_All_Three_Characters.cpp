// LEETCODE - 1358


// TLE
// TC : O(n^2)
// AS : O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(3, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                bool atLeastOne = true;
                for (int k = 0; k < 3; k++) {
                    if (freq[k] == 0) {
                        atLeastOne = false;
                        break;
                    }
                }
                
                if (atLeastOne) cnt++;
            }
        }
        return cnt;
    }
};


// OPTIMAL
// TC : O(n)
// AS : O(1)
class Solution {
public:
    int numberOfSubstrings(string str) {
        int n = str.length();

        int freq[3] = {0};
        int s = 0, e = 0, cnt = 0;
        freq[str[e] - 'a']++;

        while (e < n){
            bool atLeastOne = true;
            if (!freq[0] || !freq[1] || !freq[2]) {
                atLeastOne = false;
            }

            if (atLeastOne){
                cnt += n - e;
                freq[str[s] - 'a']--;
                s++;
            }else {
                e++;
                if (e < n) freq[str[e] - 'a']++;
            }

        }
        return cnt;
    }
};