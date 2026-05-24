// LEETCODE - 735. Asteroid Collision


// TC : O(n)
// AS : O(n)
// SC : O(2n) = O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector <int> ans;
        stack <int> s;
        for (int i=n-1; i>=0; i--){
            if (asteroids[i] < 0){
                s.push(asteroids[i]);
            }else {
                    while (!s.empty() && s.top() < 0 &&  -(s.top()) < asteroids[i]){
                        s.pop();
                    }
                    if (!s.empty() && s.top() < 0 &&  -(s.top()) == asteroids[i]) {
                        s.pop();
                    }
                    else if (!s.empty() && s.top() < 0 && -(s.top()) > asteroids[i]) continue;
                    else s.push(asteroids[i]);
            }
        }

        while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};


// TC : O(n)
// AS : O(n)
// SC : O(2n) = O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector <int> ans;
        stack <int> s;
        for (int i=0; i<n; i++){
            if (asteroids[i] > 0){
                s.push(asteroids[i]);
            }else {
                while (!s.empty() && s.top() > 0 && -(asteroids[i]) > s.top()){
                    s.pop();
                }
                if (!s.empty() && s.top() > 0 && -(asteroids[i]) == s.top()){
                    s.pop();
                }
                else if (s.empty() || s.top() < 0){
                    s.push(asteroids[i]); 
                } 
            }
        }

        while (!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};