// LEETCODE - 912. Sort an Array

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};



class Solution {
public:
    void merge(vector<int> &nums, int s, int m, int e){
        vector<int> arr;
        int i = s;
        int j = m + 1;

        while (i <= m && j <= e){
            if (nums[i] <= nums[j]) arr.push_back(nums[i++]);
            if (nums[i] > nums[j]) arr.push_back(nums[j++]);
        }

        while(i <= m) arr.push_back(nums[i++]);
        while(j <= e) arr.push_back(nums[j++]);

        for (int i=0; i<arr.size(); i++){
            nums[i+s] = arr[i];
        }
    }

    void mergeSort(vector<int> &nums, int s, int e){
        if (s >= e) return;
        int m = s + (e - s)/2;

        mergeSort(nums, s, m);
        mergeSort(nums, m+1, e);
        merge(nums, s, m, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        // TC : O(nlogn)
        // AS : O(n)
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};




class Solution {
public:
    int findPivotIndex(vector<int> &nums, int s, int e){
        int pivot = s;
        int i = s;
        int j = e;
        while (i <= j){
            while (i <= e && nums[i] <= nums[pivot]) i++;
            while (j >= s && nums[j] > nums[pivot]) j--;
            if (i < j) swap(nums[i++], nums[j--]);
        }

        swap(nums[pivot], nums[j]);
        return j;
    }


    void quickSort(vector<int> &nums, int i, int j){
        if (i >= j) return;
        int partition = findPivotIndex(nums, i, j);
        quickSort(nums, i, partition-1);
        quickSort(nums, partition+1, j);
    }


    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};




class Solution {
public:
    void insert(vector<int> &nums, int temp){
        int n = nums.size();
        if (n == 0 || nums[n-1] <= temp){
            nums.push_back(temp);
            return;
        }

        int val = nums[n-1];
        nums.pop_back();
        insert(nums, temp);
        nums.push_back(val);
    }
  
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums;

        int temp = nums[n-1];
        nums.pop_back();

        sortArray(nums);
        insert(nums, temp);

        return nums;
    }
};