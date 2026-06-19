// LEETCODE - 739 Daily Temperatures

// BRUTE FORCE APPROACH
// TC : O(n^2)
// AS : O(1)
// SC : O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> answer(n, 0);

        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (temperatures[j] > temperatures[i]){
                    answer[i] = j - i;
                    break;
                }
            }
        }

        return answer;
    }
};


// OPTIMAL APPROACH
// TC : O(2n) = O(n)
// AS : O(n)
// SC : O(2n) = O(n)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        vector <int> answer(n, 0);
        stack <int> s;

        for (int i=n-1; i>=0; i--){
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]){
                s.pop();
            }
            answer[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }

        return answer;
    }
};