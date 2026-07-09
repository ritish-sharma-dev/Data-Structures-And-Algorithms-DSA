// LEETCODE - 509. Fibonacci Number


// TC : O(n)
// AS : O(1)
class Solution {
public:
    int fib(int n) {

        if (n <= 1) return n;

        int firstNumber = 0, secondNumber = 1, res;

        int i = 0;
        while (i <= n-2){
            res = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = res;
            i++;
        }
        return res;
    }
};


// TC : O(n)
// AS : O(n)
class Solution {
public:
    int fibonacci(int n){
        if (n <= 1) return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }

    int fib(int n) {
        return fibonacci(n);
    }
};



class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        return fib(n -1) + fib(n - 2);
    }
};