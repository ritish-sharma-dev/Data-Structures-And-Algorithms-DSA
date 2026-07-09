// GFG

class Solution {
  public:
    int f(int n, int sum){
        if (n == 0){
            if (sum % 10 == sum) return sum;
            return f(sum, 0);
        }
        
        sum += n % 10;
        n = n / 10;
        return f(n, sum);
    }
    
    int digitalRoot(int n) {
        return f(n, 0);
    }
};