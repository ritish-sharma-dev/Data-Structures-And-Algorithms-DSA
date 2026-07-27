// LEETCODE - 4000




class Solution {
public:
    
    void f(int requiredLen, int requiredSum, int number, int &largestNumber){
        if (requiredSum == 0) {
            largestNumber = max(number, largestNumber);
        }
        if (requiredLen == 0){
            return;
        }

        for (int i = 9; i >= 0; i--){
            f(requiredLen - 1, requiredSum - i, number * 10 + i, largestNumber);
        }
    }
    
    int largestInteger(int n, int s) {
        int largestNumber = -1;

        f(n, s, 0, largestNumber);

        return largestNumber;
    }
};