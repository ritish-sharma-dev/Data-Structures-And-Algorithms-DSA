#include<iostream>
using namespace std;

// TC : O(n)
// SC : O(n) -> recursive stack space
void print(int i, int n){
    if(i > n) return;
    cout<<i<<" Ritish Sharma"<<endl;
    print(i+1, n);
}

int main()
{
    int n;
    cin>>n;
    print(1, n);
    return 0;
}