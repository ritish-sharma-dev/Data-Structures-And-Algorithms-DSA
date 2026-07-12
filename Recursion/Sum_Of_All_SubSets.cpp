#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// void SumOfAllSubsets(int i, int n,vector<int> &nums, int sum, vector<int> &ans){
//     if (i >= n){
//         ans.push_back(sum);
//         return;
//     }

//     SumOfAllSubsets(i+1, n, nums, sum + nums[i], ans);
//     SumOfAllSubsets(i+1, n, nums, sum, ans);
// }


// int main()
// {
//     int n;
//     cin>>n;

//     vector<int> nums(n);

//     for (int i=0; i<n; i++){
//         cin>>nums[i];
//     }

//     vector<int> ans;
//     int sum = 0;
//     SumOfAllSubsets(0, n, nums, sum, ans);

//     sort(ans.begin(),ans.end());

//     for (int x : ans){
//         cout<<x<<" ";
//     }
//     return 0;
// }



