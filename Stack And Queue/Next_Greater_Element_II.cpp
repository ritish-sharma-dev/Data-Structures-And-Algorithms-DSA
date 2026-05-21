// LEETCODE - 503. Next Greater Element II


// BRUTE FORCE APPROACH
// TC : O(n^2)
// AS : O(1)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            bool nextGreaterFound = false;
            for (int j=i+1; j<n; j++) {
                if (nums[j] > nums[i]) {
                    ans[i] = nums[j];
                    nextGreaterFound = true;
                    break;
                }
            }
            if (!nextGreaterFound) {
                for (int k=0; k<i; k++) {
                    if (nums[k] > nums[i]) {
                        nextGreaterFound = true;
                        ans[i] = nums[k];
                        break;
                    }
                }
            }
            if (!nextGreaterFound) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};


// TC :O(n^2)
// AS : O(1)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n, -1);
        for (int i=0; i<n; i++){
            for (int j=i+1; j<i+n; j++){
                int idx = j%n;
                if (nums[idx] > nums[i]){
                    ans[i] = nums[idx];
                    break;
                }
            }
        }
        return ans;
    }
};



// OPTIMIZED APPROACH
// TC : O(n)
// AS : O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        stack <int> s;
        for (int i=n-2; i>=0; i--){
            s.push(nums[i]);
        }
        for (int j=n-1; j>=0; j--){
            while (!s.empty() && s.top() <= nums[j]){
                s.pop();
            }
            if (s.empty()) ans[j] = -1;
            else ans[j] = s.top();
            s.push(nums[j]);
        }
        return ans;
    }
};


// OPTIMIZED APPROACH
// TC : O(4n) = O(n)
// AS : O(2n) = O(n)
// SC : O(2n + n) = O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        stack <int> s;
        for (int i=2*n-1; i>=0; i--){
            int idx = i%n;
            while (!s.empty() && s.top() <= nums[idx]){
                s.pop();
            }
            if (i < n){
                if (s.empty()) ans[i] = -1;
                else ans[i] = s.top();
            }
            s.push(nums[idx]);
        }
        return ans;
    }
};