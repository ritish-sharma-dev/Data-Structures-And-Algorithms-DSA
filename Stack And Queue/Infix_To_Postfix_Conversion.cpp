#include <bits/stdc++.h>
using namespace std;

bool isOperand(char x){
    if (x >= 'A' && x <= 'Z' ||
        x >= 'a' && x <= 'z' ||
        x >= '0' && x <= '9' ){
        return true;
    }
    return false;
}

int priority(char x){
    if (x == '^'){
        return 3;
    }else if (x == '*' || x == '/'){
        return 2;
    }else if (x == '+' || x == '-'){
        return 1;
    }
    return -1;
}

string infixToPostfixConversion(string s){
    // TC : O(n) + O(n)
    // SC : O(n) + O(n)
    // AS : O(n)
    int n = s.length();
    stack <char> st;
    string ans = "";
    int i=0;
    while (i < n){
        if (isOperand(s[i])){
            ans += s[i];
        }else if (s[i] == '('){
            st.push(s[i]);
        }else if (s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }else {
            if (s[i] == '^') {
					while (!st.empty() && priority(s[i]) < priority(st.top())) {
						ans += st.top();
						st.pop();
					}
				} else {
                while (!st.empty() && priority(s[i]) <= priority(st.top()) ){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        i++;
    }

    while (!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}


int main(){

    string s;
    getline(cin, s);

    string str = infixToPostfixConversion(s);
    for (int i=0; i<str.length(); i++){
        cout<<str[i];
    }
    return 0;
}