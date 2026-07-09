// GFG


// RECURSION
// TC : O(n)
// AS : O(n)
class Solution {
  public:
    void f(vector<int> &ans, int n){
        if (n <= 0) {
            ans.push_back(n);
            return;
        }
        ans.push_back(n);
        f(ans, n-5);
        ans.push_back(n);
    }
    
    vector<int> pattern(int n) {
        vector <int> ans;
        
        f(ans, n);
        
        return ans;
    }
};