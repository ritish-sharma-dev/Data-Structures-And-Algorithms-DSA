#include <bits/stdc++.h>
using namespace std;

void findSubsequencesWithSumK(int i, vector<int> &nums, int k, int sum, vector<int> &s, vector<vector<int>> &ans){
    // BASE CASE
    if (i >= nums.size()){
        if (sum == k){
            ans.push_back(s);
        }
        return;
    }

    // INCLUDE
    s.push_back(nums[i]);
    sum += nums[i];
    findSubsequencesWithSumK(i+1, nums, k, sum, s, ans);

    // EXCLUDE
    sum -= nums[i];
    s.pop_back();
    findSubsequencesWithSumK(i+1, nums, k, sum, s, ans);
}


int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    int k;
    cin>>k;

    vector<vector<int>> ans;
    vector<int> s;
    findSubsequencesWithSumK(0, nums, k, 0, s, ans);

    for (auto i : ans){
        for (auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}