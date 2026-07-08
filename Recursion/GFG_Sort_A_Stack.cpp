// GFG


// TC : O(n + nlogn + n) = O(nlogn)
// AS : O(n)
class Solution {
  public:
    void sortStack(stack<int> &s) {
        vector<int> arr;
        
        while (!s.empty()){
            arr.push_back(s.top());
            s.pop();
        }
        
        sort(arr.begin(), arr.end());
        
        for (int x : arr){
            s.push(x);
        }
    }
};


// TC : O(n^2)
// AS : O(n) used for recursion stack 
class Solution {
  public:
    void insert(stack<int> &s, int temp){
        if (s.empty() || s.top() <= temp){
            s.push(temp);
            return;
        }
        
        int v = s.top();
        s.pop();
        insert(s, temp);
        s.push(v);
    }
    
    void sortStack(stack<int> &s) {
        int n = s.size();
        
        if (n == 1) return;
        
        int temp = s.top();
        s.pop();
        
        sortStack(s);
        insert(s, temp);
    }
};

