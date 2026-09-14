// n = length of string
// TC : O(n)
// SC : O(n)

#include <bits/stdc++.h>
using namespace std;

bool isConsonant(char c){
    return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != 'Y');
}

bool isUpperCase(char c){
    return c >= 'A' && c <= 'Z';
}

int main() {
    string s;
    getline(cin, s);

    string ans;
    for (int i = 0; i < s.length(); i++){
        if (isConsonant(s[i])){
            ans += '.';
            if (isUpperCase(s[i])) ans += s[i] + 32;
            else ans += s[i];
        }
    }

    cout<<ans;

    return 0;
}