// LEETCODE - 907. Sum of Subarray Minimums

// TC : O(n^3)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    long long findMin(vector <int>& arr, int i, int j){
        long long min = INT_MAX;
        for (int x=i; x<=j; x++){
            if (arr[x] < min) min = arr[x];
        }
        return min;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        long long mod = 1e9 + 7;
        for (int i=0; i<n; i++){
            for (int j=i; j<n; j++){
                sum = (sum + findMin(arr, i, j)) % mod;
            }
        }
        return sum;
    }
};


// TC : O(n^2)
// AS : O(1)
// SC : O(1)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        long long mod = 1e9 + 7;
        
        for (int i=0; i<n; i++){
            int minValue = arr[i];
            for (int j=i; j<n; j++){
                minValue = min(minValue, arr[j]);
                sum = (sum + minValue) % mod;
            }
        }
        return sum;
    }
};


// TC : O(n)
// AS : O(n)
// SC : O(n)
class Solution {
public:
    vector<int> leftSmallestElementIndex(vector<int> &arr){
        vector<int> x(arr.size());
        stack<pair<int,int>> s1;

        for (int i=0; i<arr.size(); i++){
            while (!s1.empty() && s1.top().first >= arr[i]){
                s1.pop();
            }
            if (s1.empty()) x[i] = -1;
            else x[i] = s1.top().second;
            s1.push({arr[i], i});
        }
        return x;
    }

    vector<int> rightSmallestElementIndex(vector<int> &arr){
        vector<int> y(arr.size());
        stack<pair<int,int>> s2;

        for (int i=arr.size()-1; i>=0; i--){
            while (!s2.empty() && s2.top().first > arr[i]){
                s2.pop();
            }
            if (s2.empty()) y[i] = arr.size();
            else y[i] = s2.top().second;
            s2.push({arr[i], i});
        }
        return y;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector <int> x = leftSmallestElementIndex(arr);
        vector <int> y = rightSmallestElementIndex(arr);

        long long sum = 0;
        long long mod = 1e9 + 7;
        for (int i=0; i<n; i++){
            sum = (sum + (1LL*(i-x[i])*(y[i]-i)%mod*arr[i])%mod)%mod; 
        }
        return sum;
    }
};