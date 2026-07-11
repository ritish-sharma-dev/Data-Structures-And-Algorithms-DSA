#include<iostream>
#include<vector>
using namespace std;

void findAllSubSequences(int i, vector<int> &nums, vector<int> &s, vector<vector<int>> &ans){
    // BASE CASE
    if (i >= nums.size()){
        ans.push_back(s);
        return;
    }

    // INCLUDE
    s.push_back(nums[i]);
    findAllSubSequences(i + 1, nums, s, ans);

    // EXCLUDE
    s.pop_back();
    findAllSubSequences(i + 1, nums, s, ans);
}

int main()
{
    int n;
    cin>>n;
    vector <int> nums(n);

    for (int i = 0; i < n; i++){
        cin>>nums[i];
    }

    vector <vector<int>> ans;
    vector <int> s;
    findAllSubSequences(0, nums, s, ans);

    cout<<"All Subsequences are: "<<endl;
    for (auto i: ans){
        for (auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}