// LEETCODE : 860. Lemonade Change


// TC : O(n)
// AS : O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int five = 0, ten = 0, twenty = 0;
        for (int bill : bills) {
            if (bill == 5){
                five++;
            }else if (bill == 10){
                ten++;
                if (five == 0) return false;
                five--;
            }else if (bill == 20){
                twenty++;
                if (five > 0 && ten > 0) five--, ten--;
                else if (five > 2) five -= 3;
                else return false;
            }
        }
        return true;
    }
};