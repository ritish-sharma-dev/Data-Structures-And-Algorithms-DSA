#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue <int> q;

    public:
    void push(int x){
        q.push(x);
        int size = q.size();
        for (int i=0; i<size-1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        if (q.size() == 0) {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        int poppedValue = q.front();
        q.pop();
        return poppedValue;
    }

    int top(){
        if (q.size() == 0) {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return q.front();
    }

    int size(){
        return q.size();
    }

    bool isEmpty(){
        return q.size() == 0;
    }
};


int main(){
    Stack s;
    s.push(10);
    cout<<s.top()<<endl;
    s.push(20);
    cout<<s.top()<<endl;
    s.push(30);
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.top()<<endl;
    return 0;
}