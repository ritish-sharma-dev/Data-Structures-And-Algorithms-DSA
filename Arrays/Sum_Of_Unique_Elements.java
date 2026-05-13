// LEETCODE - 1748 Sum of Unique Elements


// BRUTE FORCE APPROACH
// TC : O(n^2)
// AS : O(1)
class Solution {
    public int sumOfUnique(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for (int i=0; i<n; i++){
            int freq = 0;
            for (int j=0; j<n; j++){
                if (nums[i] == nums[j]) freq++;
            }
            if (freq == 1) sum += nums[i];
        }
        return sum;
    }
}


// BETTEr APPROACH - hashing
// TC : O(2n) = O(n)
// AS : O(n)
class Solution {
    public int sumOfUnique(int[] nums) {
        int n = nums.length;
        int sum = 0;
        HashMap <Integer, Integer> mp = new HashMap();
        for (int x : nums){
            if (mp.containsKey(x)) mp.put(x, mp.get(x)+1);
            else mp.put(x, 1);
        }
        for (int y : mp.keySet()){
            if (mp.get(y) == 1) sum += y;
        }
        return sum;
    }
}


// OPTIMISED APPROACH - using constant frequency array as the range of values in the arrays is from 0 to 100
// TC : O(n)
// AS : O(1)
class Solution {
    public int sumOfUnique(int[] nums) {
        int n = nums.length;
        int sum = 0;
        int []freqArray = new int[101];
        for (int x : nums){
            freqArray[x]++;
        }
        for (int i=0; i<101; i++){
            if (freqArray[i] == 1) sum += i;
        }
        return sum;
    }
}