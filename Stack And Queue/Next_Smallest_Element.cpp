// https://www.naukri.com/code360/problems/next-greater-element_11125


#include<bits/stdc++.h>
#include<vector>
using namespace std;

// TC : O(n^2)
// AS : O(1)
// vector<int> nextSmallestElement(vector <int> &arr, int n){
//     vector <int> ans(n, -1);
//     for (int i=0; i<n; i++){
//         for (int j=i+1; j<n; j++){
//             if (arr[j] < arr[i]){
//                 ans[i] = arr[j];
//                 break;
//             }
//         }
//     }
//     return ans;
// }


// TC : O(2n) = O(n)
// AS : O(n)
// SC : O(2n) = O(n)
vector<int> nextSmallestElement(vector<int> &arr, int n){
    vector <int> ans(n);
    stack <int> st;

    for (int i=n-1; i>=0; i--){
        while (!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}


int main()
{
    vector <int> arr = {1, 2, 3, 4};
    vector <int> ans = nextSmallestElement(arr, arr.size());
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}