// LEETCODE - 239 Sliding Window Maximum


// BRUTE FORCE
// TC : O((n-k+1)*k) = O(n*k)
// AS : O(1)
// SC : O(n-k+1) = O(n)       
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector <int> ans;
        int start = 0;
        int end = k - 1;
        while (end < n){
            int maxVal = INT_MIN;
            for (int i=start; i<=end; i++){
                maxVal = max(maxVal, nums[i]);
            }
            ans.push_back(maxVal);
            start++;
            end++;
        }
        return ans;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(k)
// SC : O(n-k+1) + O(k) = O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector <int> ans;
        deque <int> deq;

        for (int i=0; i<n; i++){
            while (!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }

            while (!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(i);

            if (i >= k-1){
                ans.push_back(nums[deq.front()]);
            }
        }

        return ans;
    }
};