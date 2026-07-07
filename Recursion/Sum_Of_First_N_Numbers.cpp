// TC : O(n)
// SC : O(n)

// PARAMETERIZED WAY
// #include<iostream>
// using namespace std;
// int sum(int i, int n, int s){
//     if (i > n) return s;
//     sum(i+1, n, s + i);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int s = sum(1, n, 0);
//     cout<<s<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;

// int sum(int i, int s){
//     if (i < 1) return s;
//     sum(i-1, s + i);
// }

// int main()
// {
//     int n;
//     cin>>n;

//     int s = sum( n, 0);
//     cout<<s<<endl;
//     return 0;
// }



// FUNCTIONAL WAY
#include<iostream>
using namespace std;

int sum(int n){
    if (n == 0) return 0;
    return n + sum(n-1);
}

int main()
{
    int n;
    cin>>n;
    int s = sum(n);
    cout<<s<<endl;
    return 0;
}