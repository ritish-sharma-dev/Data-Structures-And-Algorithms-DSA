// TC : O(n*m)
// SC : O(n)
// AS : O(1)
vector<int> countGreater(vector<int>&arr, vector<int>&query) {
    int m = arr.size();
    int n = query.size();
    vector<int> ans(n);
    for (int i=0; i<n; i++){
        int idx = query[i];
        int count = 0;
        for (int j=idx+1; j<m; j++){
            if (arr[j] > arr[idx]){
                count++;
            } 
        }
        ans[i] = count;
    }
    return ans;
}