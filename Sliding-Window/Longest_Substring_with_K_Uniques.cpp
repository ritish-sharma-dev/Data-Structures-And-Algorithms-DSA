// GEEKSFORGEEKS : LONGEST SUBSTRING WITH K UNIQUE CHARACTERS

// TC : O(n)
// AS : O(1)
class Solution {
  public:
    int findDistChar(vector<int> &v){
        int distChar = 0;
        for (int i=0; i<26; i++){
            if (v[i] > 0) distChar++;
        }
        return distChar;
    }
    
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        
        vector<int> v(26, 0);
        int maxSubLen = -1;
        
        int i = 0, j = 0;
        while (j < n){
            v[s[j] - 'a']++;
            
            int distChar = findDistChar(v);
            
            while (distChar > k){
                v[s[i] - 'a']--;
                i++;
                distChar = findDistChar(v);
            }
            
            if (distChar == k) maxSubLen = max(maxSubLen, j - i + 1);
            j++;
        }
        
        return maxSubLen;
    }
};