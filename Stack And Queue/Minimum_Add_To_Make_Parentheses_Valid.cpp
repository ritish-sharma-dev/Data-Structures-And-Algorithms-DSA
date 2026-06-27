// LEETCODE - 921


// BRUTE FORCE APPROACH
// TC : O(2n) = O(n)
// AS : O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        for (char x : s){
            if (x == '('){
                st.push(x);
            }else {
                if (!st.empty() && st.top() == '('){
                    st.pop();
                }else {
                    st.push(x);
                }
            }
        }

        int numberOfMoves = 0;
        while (!st.empty()){
            numberOfMoves++;
            st.pop();
        }

        return numberOfMoves;
    }
};


// BETTER APPROACH
// TC : O(n)
// AS : O(n)
// SC : O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        stack <int> st;
        int noOfMoves = 0;
        for (char x : s){
            if (x == '('){
                st.push(x);
                noOfMoves++;
            }else {
                if (!st.empty() && st.top() == '('){
                    st.pop();
                    noOfMoves--;
                }else{
                    st.push(x);
                    noOfMoves++;
                }
            }
        }
        return noOfMoves;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int l = 0, r = 0;
        for (char x : s){
            if (x == '('){
                l++;
            }else {
                (l > 0) ? l-- : r++;
            }
        }
        return l + r;
    }
};