// GFG

// NORMAL METHOD
// TC : O(n)
// AS : O(n/2) = O(n)
class Solution {
  public:
    void deleteMid(stack<int>& s) {
        int size = s.size();
        int middle = floor(size + 1)/2;
        
        stack<int> x;
        
        int pos = size;
        while (!s.empty() && pos != middle){
            x.push(s.top());
            s.pop();
            pos--;
        }
        s.pop();
        
        while (!x.empty()){
            s.push(x.top());
            x.pop();
        }
    }
};


// USING RECURSION
// TC : O(n)
// SC : O(n/2) = O(n) used for recursion stack
class Solution {
  public:
    void deleteMidElement(stack<int> &s, int middle, int pos){
        if (pos == middle){
            s.pop();
            return;
        }
        int value = s.top();
        s.pop();
        deleteMidElement(s, middle, --pos);
        s.push(value);
    }
    
    void deleteMid(stack<int>& s) {
        int size = s.size();
        int middle = floor(size + 1)/2;
        deleteMidElement(s, middle, size);
    }
};