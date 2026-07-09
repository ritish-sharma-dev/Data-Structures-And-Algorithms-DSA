// GFG


// TC : O(2n) = O(n)
// AS : O(n)
class Solution {
  public:
    void reverseStack(stack<int> &s) {
        vector <int> arr;
        
        while (!s.empty()){
            arr.push_back(s.top());
            s.pop();
        }
        
        for (int i=0; i<arr.size(); i++){
            s.push(arr[i]);
        }
    }
};



// USING RECURSION
// TC : O(n^2)
// AS : O(n)
class Solution {
  public:
    void insert(stack<int> &s, int v){
        if (s.empty()) {
            s.push(v);
            return;
        }
        
        int x = s.top();
        s.pop();
        insert(s, v);
        s.push(x);
    }

    void reverseStack(stack<int> &s) {
        if (s.empty()) return;
        
        int v = s.top();
        s.pop();
        
        reverseStack(s);
        insert(s, v);
    }
};