class Solution {
	public:
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
		} else {
			return - 1;
		}
	}
	
	string infixToPostfix(string& s) {
        // TC : O(n) + O(n)
        // AS : O(n)
        // SC : O(n) + O(n)
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
				st.pop();
			} else {
				if (s[i] == '^') {
					while (!st.empty() && priority(s[i]) < priority(st.top())) {
						ans += st.top();
						st.pop();
					}
				} else {
					while (!st.empty() && priority(s[i]) <= priority(st.top())) {
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
};
