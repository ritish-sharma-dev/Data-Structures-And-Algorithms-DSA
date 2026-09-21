#include<bits/stdc++.h>
using namespace std;

bool isOperand(string c){
    if (c >= "A" && c <= "Z" ||
        c >= "a" && c <= "z" ){
            return true;
    }
    return false;
}

string prefixToPostfix(string &s){
    // TC : O(n)
    // AS : O(n)
    // SC : O(n)
    int n = s.length();
    stack <string> st;
    
    int i = n-1;
    while (i >= 0 ){
        string temp = string(1, s[i]);
        if (isOperand(temp)){
            st.push(temp);
        }else{
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            st.push(operand1 + operand2 + temp);
        }
        i--;
    }
    return st.top();
}

int main()
{
    string s;
    getline(cin, s);

    string res = prefixToPostfix(s);
    cout << res << endl;
    return 0;
}