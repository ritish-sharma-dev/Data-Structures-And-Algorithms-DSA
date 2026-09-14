#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    while (n--){
        string s;
        cin >> s;
        
        int len = s.length();
        string ans;

        if (len <= 10){
            ans = s;
        }else {
            int betweenChar = len - 2;
            ans += s[0] + to_string(betweenChar) + s[len - 1];
        }

        cout<<ans<<endl;
    }

    return 0;
}