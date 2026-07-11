#include<iostream>
#include<vector>
using namespace std;

int countSubsequencesWithSumK(int i, vector<int> &nums, int k, int sum){
    if (i >= nums.size()){
        if (sum == k) return 1;
        return 0;
    }

    sum += nums[i];
    int l = countSubsequencesWithSumK(i+1, nums, k, sum);

    sum -= nums[i];
    int r = countSubsequencesWithSumK(i+1, nums, k, sum);

    return l + r;
}


int main()
{
    int n;
    cin>>n;

    vector<int> nums(n);

    for (int i=0; i<n; i++){
        cin>>nums[i];
    }

    int k;
    cin>>k;

    int count = countSubsequencesWithSumK(0, nums, k, 0);
    cout<<count;
    return 0;
}