

// TC : O(n * n)
// AS : O(n)
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();

        vector <int> digitRange(n);
        int maxRange = INT_MIN;
        
        for (int i=0; i<n; i++){
            int max = INT_MIN;
            int min = INT_MAX;
            int copy = nums[i];
            while (copy > 0){
                int r = copy % 10;
                if (r > max) max = r;
                if (r < min) min = r;
                copy = copy / 10;
            }
            int range = max - min;
            if (range > maxRange) maxRange = range;
            digitRange[i] = range;
        }

        int sum = 0;
        for (int i=0; i<n; i++){
            if (digitRange[i] == maxRange) sum += nums[i];
        }

        return sum;
    }
};