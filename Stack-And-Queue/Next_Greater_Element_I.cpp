// LEETCODE - 496. Next Greater Element I


// BRUTE FORCE APPROACH
// We will check for each element of nums1 in nums2 and then check for the first next greater element in nums2 and push it to the answer vector. If we do not find any greater element then we will push -1 to the answer vector.
// TC : O(m*n)
// AS : O(1)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        int m = nums1.size();
        int n = nums2.size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (nums1[i] == nums2[j]){
                    bool greaterExist = false;
                    for (int k=j+1; k<n; k++){
                        if (nums2[k] > nums2[j]){
                            greaterExist = true;
                            ans.push_back(nums2[k]);
                            break;
                        }
                    }
                    if (!greaterExist) ans.push_back(-1);
                    break;
                }
            }
        }
        return ans;
    }
};


// OPTIMIZED APPROACH - MONOTONIC STACK + HASHMAP
// TC : O(n + m)
// AS : O(n)
// SC : O(n + m)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector <int> ans(m);
        unordered_map <int, int> mp;
        stack <int> s;
        for (int i=n-1; i>=0; i--){
            while (!s.empty() && s.top() <= nums2[i]){
                s.pop();
            }
            if (s.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = s.top();
            s.push(nums2[i]);
        }
        for (int j=0; j<m; j++){
            ans[j] = mp[nums1[j]];
        }
        return ans;
    }
};