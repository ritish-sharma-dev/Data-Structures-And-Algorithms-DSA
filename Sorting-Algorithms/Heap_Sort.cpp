class Solution {
  public:
    void heapifyDown(vector<int>&arr, int idx, int last){
        int lChildIdx = 2 * idx + 1;
        int rChildIdx = 2 * idx + 2;
        int largestIdx = idx;
        
        if (lChildIdx <= last && arr[lChildIdx] > arr[largestIdx]){
            largestIdx = lChildIdx;
        }
        if (rChildIdx <= last && arr[rChildIdx] > arr[largestIdx]){
            largestIdx = rChildIdx;
        }
        
        if (largestIdx != idx){
            swap(arr[idx], arr[largestIdx]);
            heapifyDown(arr, largestIdx, last);
        }
    }
    
    void extractMax(vector<int> &arr, int last){
        swap(arr[0], arr[last]);
        last--;
        if (last == 0) return;
        heapifyDown(arr, 0, last);
        extractMax(arr, last);
    }
    
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = n/2 - 1; i >= 0; i--){
            heapifyDown(arr, i, n - 1);
        }
        
        extractMax(arr, n - 1);
    }
};