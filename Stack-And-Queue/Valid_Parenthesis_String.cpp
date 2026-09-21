// LEETCODE - 678


// TC : O(n)
// AS : O(n)
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();

        stack <int> open;
        stack <int> star;
        for (int i=0; i<n; i++){
            if (s[i] == '('){
                open.push(i);
            }else if (s[i] == '*'){
                star.push(i);
            }else {
                if (!open.empty()){
                    open.pop();
                }else {
                    if (!star.empty() && star.top() < i){
                        star.pop();
                    }else {
                        return false;
                    }
                }
            }
        }

        while (!open.empty() && !star.empty()){
            if (open.top() > star.top()){
                return false;
            }
            open.pop();
            star.pop();
        }

        if (!open.empty()) return false;
        return true;

    }
};