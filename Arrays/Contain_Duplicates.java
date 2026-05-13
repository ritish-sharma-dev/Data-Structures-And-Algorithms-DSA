// LEETCODE - 217 Contains Duplicates


// OPTIMAL APPROACH - hashing
// TC : O(2n) = O(n)
// AS : O(n)
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap <Integer, Integer> mp = new HashMap();

        for (int x : nums){
            if (mp.containsKey(x)) mp.put(x, mp.get(x)+1);
            else mp.put(x, 1);
        }

        for (int y : mp.keySet()){
            if (mp.get(y) > 1) return true;
        }
        return false;
    }
}

// OPTIMAL APPROACH - hashing
// TC : O(n)
// AS : O(n)
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap <Integer, Integer> mp = new HashMap();

        for (int x : nums){
            if (mp.containsKey(x)) {
                return true;
            };
            mp.put(x, 1);
        }
        return false;
    }
}