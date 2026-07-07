#include<iostream>
using namespace std;

// TC : O(n)
// SC : O(n) -> recursive stack space
void print(int i, int n){
    if (i < 1) return;
    cout<<i<<endl;
    print(i-1, n);
}

int main()
{
    int n;
    cin>>n;
    print(n, n);
    return 0;
}