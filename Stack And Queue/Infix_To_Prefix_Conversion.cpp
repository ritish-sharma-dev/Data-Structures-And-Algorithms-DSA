#include <bits/stdc++.h>
using namespace std;

void reverse(string &str) {
		int start = 0;
		int end = str.length() - 1;
		while (start < end) {
			swap(str[start], str[end]);
			start++;
			end--;
		}
		
		for (char &x : str){
		    if (x == '(') x = ')';
		    else if (x == ')') x = '(';
		}
	}
	
	bool isOperand(char c) {
		if (c >= 'A' && c <= 'Z' ||
		c >= 'a' && c <= 'z' ||
		c >= '0' && c <= '9') {
			return true;
		}
		return false;
	}
	
	int priority(char c) {
		if (c == '^') {
			return 3;
		} else if (c == '*' || c == '/') {
			return 2;
		} else if (c == '+' || c == '-') {
			return 1;
		}
	    return -1;
	}
	
	string infixToPostfix(string& s) {
		int n = s.length();
		stack <char> st;
		string ans = "";
		
		int i = 0;
		while (i < n) {
			if (isOperand(s[i])) {
				ans += s[i];
			} else if (s[i] == '(') {
				st.push(s[i]);
			} else if (s[i] == ')') {
				while (!st.empty() && st.top() != '(') {
					ans += st.top();
					st.pop();
				}
				if (!st.empty()) st.pop();
			} else {
				if (s[i] == '^') {
					while (!st.empty() && priority(s[i]) <= priority(st.top())) {
						ans += st.top();
						st.pop();
					}
				} else {
					while (!st.empty() && priority(s[i]) < priority(st.top())) {
						ans += st.top();
						st.pop();
					}
				}
				st.push(s[i]);
			}
			i++;
		}
		
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		
		return ans;
	}
	
int main(){
    string s;

    getline(cin, s);

    reverse(s);
    string ans = infixToPostfix(s);
    reverse(ans);

    for (int i=0; i<ans.length(); i++){
        cout<<ans[i];
    }
    return 0;
}