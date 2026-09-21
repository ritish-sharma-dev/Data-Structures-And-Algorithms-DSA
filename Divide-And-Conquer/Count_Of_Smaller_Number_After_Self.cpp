// Leetcode : 315. Count of Smaller Numbers After Self

class Solution {

    // TC : O(nlogn)
    // AS : O(n)

public:
    
    void merge(vector<vector<int>> &x, int s, int m, int e, vector<int> &ans){
        int i = m;
        int j = e;

        vector<vector<int>> sortArray(e - s + 1);
        int k = e - s;

        while (i >= s && j >= m + 1){
            if (x[j][1] < x[i][1]){
                ans[x[i][0]] += j - (m + 1) + 1;
                sortArray[k--] = x[i--];
            }else sortArray[k--] = x[j--];
        }

        while(i >= s) sortArray[k--] = x[i--];
        while (j >= m + 1) sortArray[k--] = x[j--];

        for (int i = 0; i < sortArray.size(); i++){
            x[i + s] = sortArray[i];
        }
    }

    void mergeSort(vector<vector<int>> &x, int s, int e, vector<int> &ans){
        if (s >= e) return;

        int m = s + (e - s)/2;

        mergeSort(x, s, m, ans);
        mergeSort(x, m + 1, e, ans);
        merge(x, s, m, e, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> x(n);

        for (int i = 0; i < n; i++){
            x[i] = { i, nums[i] };
        }

        vector<int> ans(n, 0);

        mergeSort(x, 0, n - 1, ans);

        return ans;
    }
};