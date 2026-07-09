// LEETCODE : 1287. Element Appearing More Than 25% In Sorted Array


// BRUTE FORCE APPROACH
// TC : O(2n) = O(n)
// AS : O(n)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        unordered_map <int, int> mp;
        for(int x : arr){
            mp[x]++;
        }

        int ans = -1;
        for (auto y : mp){
            if (y.second > 0.25*n) ans = y.first;
        }

        return ans;
    }
};



// OPTIMAL APPROACH
// TC : O(n)
// AS : O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();

        int i = 0, j = 0, cnt = 0, ans = -1;
        while (j < n){
            while (j < n && arr[i] == arr[j]){
                cnt++;
                j++;
            }

            if (cnt > 0.25*n) {
                ans = arr[i];
                break;
            }
            i = j;
            cnt = 0;
        }
        return ans;
    }
};