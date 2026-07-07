#include<iostream>
using namespace std;

// Recursion is a function which calls itself. until the base condition is met. 
// Base condition is the condition which stops the recursion. (not used in this code)

// Recusion = function calling itself + Base condition

void f(){
    cout<<"1";
    f(); // function calling itself
}
// Stack Overflow : when the recursive function calls itself infinite times. the the recursion stack will be full and the program will crash.

int main()
{
    f();

    return 0;
}

