// LEETCODE - 2104. Sum of Subarray Ranges

// BRUTE FORCE APPROACH
// TC : O(n^3)
// AS : O(1)
class Solution {
public:
    int findMax(vector <int> &nums, int i, int j){
        int max = INT_MIN;
        for (int x=i; x<=j; x++){
            if (nums[x] > max) max = nums[x];
        }
        return max;
    }

    int findMin(vector <int> &nums, int i, int j){
        int min = INT_MAX;
        for (int x=i; x<=j; x++){
            if (nums[x] < min) min = nums[x];
        }
        return min;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n  = nums.size();
        long long sum = 0;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                int max = findMax(nums, i, j);
                int min = findMin(nums, i, j);
                sum += max-min;
            }
        }
        return sum;
    }
};


// BETTER APPROACH
// TC : O(n^2)
// AS : O(1)
class Solution {
public:
    int findMax(int x, int y){
        if (x > y) return x;
        return y;
    }

    int findMin(int x, int y){
        if (x < y) return x;
        return y;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n  = nums.size();
        long long sum = 0;
        for (int i=0; i<n; i++){
            int max = nums[i];
            int min = nums[i];
            for (int j=i; j<n; j++){
                max = findMax(max, nums[j]);
                min = findMin(min, nums[j]);
                sum += max-min;
            }
        }
        return sum;
    }
};


// OPTIMAL APPROACH
// TC : O(n)
// AS : O(n)
class Solution {
public:
    long long sumOfSubArrayMaximum(vector<int> &nums){
        int n = nums.size();
        vector<int> NGR(n);
        stack<pair<int, int>> s1;
        for (int i=n-1; i>=0; i--){
            while (!s1.empty() && s1.top().first < nums[i]){
                s1.pop();
            }
            if (s1.empty()) NGR[i] = n;
            else NGR[i] = s1.top().second;
            s1.push({nums[i], i});
        }

        vector<int> NGL(n);
        stack<pair<int, int>> s2;
        for (int i=0; i<n; i++){
            while (!s2.empty() && s2.top().first <= nums[i]){
                s2.pop();
            }
            if (s2.empty()) NGL[i] = -1;
            else NGL[i] = s2.top().second;
            s2.push({nums[i], i});
        }

        long long sum = 0;
        for (int i=0; i<n; i++){
            sum += (long long)((i-NGL[i])*(NGR[i]-i))*nums[i];
        }
        return sum;   
    }

    long long sumOfSubArrayMinimun(vector<int> &nums){
        int n = nums.size();
        vector<int> NSR(n);
        stack<pair<int, int>> s1;
        for (int i=n-1; i>=0; i--){
            while (!s1.empty() && s1.top().first > nums[i]){
                s1.pop();
            }
            if (s1.empty()) NSR[i] = n;
            else NSR[i] = s1.top().second;
            s1.push({nums[i], i});
        }

        vector<int> NSL(n);
        stack<pair<int, int>> s2;
        for (int i=0; i<n; i++){
            while (!s2.empty() && s2.top().first >= nums[i]){
                s2.pop();
            }
            if (s2.empty()) NSL[i] = -1;
            else NSL[i] = s2.top().second;
            s2.push({nums[i], i});
        }

        long long sum = 0;
        for (int i=0; i<n; i++){
            sum += (long long)((i-NSL[i])*(NSR[i]-i))*nums[i];
        }
        return sum; 
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumOfSubArrayMaximum(nums) - sumOfSubArrayMinimun(nums);
    }
};