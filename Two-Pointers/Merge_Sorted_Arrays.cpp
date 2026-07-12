// LEETCODE - 88


// TC : O(m + n)
// AS : O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int x = m + n - 1;

        while (i >= 0 && j >= 0){
            if (nums1[i] >= nums2[j]) nums1[x] = nums1[i--];
            else nums1[x] = nums2[j--];
            x--;
        }

        while (j >= 0) nums1[x--] = nums2[j--];
    }
};