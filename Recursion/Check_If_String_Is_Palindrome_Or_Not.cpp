#include<iostream>
using namespace std;

bool checkPalidrome(string &s, int i, int j){
    if (i >= j) return true;
    if (s[i] != s[j]) return false;
    return checkPalidrome(s, ++i, --j);
}

int main()
{
    string s;
    getline(cin, s);

    bool palindrome = checkPalidrome(s, 0, s.length()-1);
    cout<<palindrome<<endl;
    return 0;
}