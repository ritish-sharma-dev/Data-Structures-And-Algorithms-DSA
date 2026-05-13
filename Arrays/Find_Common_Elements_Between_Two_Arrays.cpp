// LEETCODE - 2956 Find Common Elements Between Two Arrays


// BRUTE FORCE APPROACH
// The intution is that we want to find the common elements between the two arrays and count their frequencies and return array of len 2 where the first element is the count of common elements in nums1 and the second element is the count of common elements in nums2.
// i will take each value from the nums1 and check if it is present in the nums2 and if it is present then i will increment the count of common elements in nums1 and move to the next value in nums1 and repeat.
// then i will take each value from the nums2 and check if it is present in the nums1 and if it is present then i will increment the count of common elements in nums2 and move to the next value in nums2 and repeat. at the end return the ans array
// TC : O(m*n)
// SC : O(1)
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(2, 0);

        int answer1 = 0;
        int answer2 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums1[i] == nums2[j]) {
                    answer1++;
                    break;
                }
            }
        }

        for (int k = 0; k < n; k++) {
            for (int l = 0; l < m; l++) {
                if (nums2[k] == nums1[l]) {
                    answer2++;
                    break;
                }
            }
        }
        ans[0] = answer1;
        ans[1] = answer2;

        return ans;
    }
};


// BETTER APPROACH - hashing
// TC : O(m+n)
// AS : O(m+n)
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(2, 0);

        unordered_map <int, int> mp1;
        unordered_map <int, int> mp2;
        for (int x : nums1) mp1[x]++;
        for (int y : nums2) mp2[y]++;
        int answer1 = 0;
        int answer2 = 0;
        for (auto i : mp1){
            if (mp2.find(i.first) != mp2.end()){
                answer1 += i.second;
            }
        }
        for (auto j : mp2){
            if (mp1.find(j.first) != mp2.end()){
                answer2 += j.second;
            }
        }
        ans[0] = answer1;
        ans[1] = answer2;

        return ans;
    }
};

// OPTIMISED APPROACH - using constant frequency array as the range of values in the arrays is from 0 to 100
// TC : O(m+n)
// AS : O(1)
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(2, 0);

        vector <int> freqArray1(101);
        vector <int> freqArray2(101);
        for (int x : nums1) freqArray1[x]++;
        for (int y : nums2) freqArray2[y]++;
        int answer1 = 0;
        int answer2 = 0;
        for (int i=0; i<101; i++){
            if (freqArray1[i] != 0 && freqArray2[i] != 0){
                answer1 += freqArray1[i];
            }
        }
        for (int i=0; i<101; i++){
            if (freqArray2[i] != 0 && freqArray1[i] != 0){
                answer2 += freqArray2[i];
            }
        }
        ans[0] = answer1;
        ans[1] = answer2;
        return ans;
    }
};