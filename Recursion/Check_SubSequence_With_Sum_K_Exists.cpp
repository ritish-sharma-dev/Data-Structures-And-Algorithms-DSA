#include<iostream>
#include<vector>
using namespace std;

bool findSubsequencesWithSumKExists(int i, vector<int> &nums, int k, int sum){
    // BASE CONDITION
    if (i >= nums.size()){
        if (sum == k) return true;
        return false;
    }

    // INCLUDE
    sum += nums[i];
    if (findSubsequencesWithSumKExists(i+1, nums, k, sum)) return true;

    // EXCLUDE
    sum -= nums[i];
    if (findSubsequencesWithSumKExists(i+1, nums, k, sum)) return true;

    return false;
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

    bool check = findSubsequencesWithSumKExists(0, nums, k, 0);
    cout<<check<<endl;
    return 0;
}