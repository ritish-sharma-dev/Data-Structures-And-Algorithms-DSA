// Coding Ninjas


// TC : O(n)
// AS : O(1)
int findDistChar(vector<int> &v){
    int distChar = 0;
    for (int i=0; i<26; i++){
        if (v[i] > 0) distChar++;
    }
    return distChar;
}

int kDistinctChars(int k, string &str)
{
    int n = str.length();

    vector<int> v(26, 0);
    int maxSubLen = 0;

    int i = 0, j = 0;
    while (j < n){
        v[str[j] - 'a']++;

        int distChar = findDistChar(v);

        while (distChar > k){
            v[str[i] - 'a']--;
            i++;
            distChar = findDistChar(v);
        }

        maxSubLen = max(maxSubLen, j - i + 1);
        j++;
    }
    return maxSubLen;
}


