#include <bits/stdc++.h>
#include <vector>
using namespace std;

// TC : O(2n)
// AS : O(n)
// SC : O(n) 
vector<int> findNextGreaterElement(vector <int> &v){
    int n = v.size();
    vector <int> ans(n,0);
    stack <int> s;
    for (int i=n-1; i>=0; i--){
        while (!s.empty() && s.top() <= v[i]){
            s.pop();
        }
        if (s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(v[i]);
    }
    return ans;
}

int main(){
    vector <int> v = {10, 1, 3, 2, 4, 8, 5, 7};
    vector <int> ans = findNextGreaterElement(v);
    for (int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}