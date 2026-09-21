#include <bits/stdc++.h>
using namespace std;


// // use when push < pop, peek
// class Queue {
//     stack <int> s1;
//     stack <int> s2;

//     public:
//     void push(int x){
//         // TC : O(2n)
//         int s1size = s1.size();
//         for (int i=0; i<s1size; i++){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         int s2size = s2.size();
//         for (int i=0; i<s2size; i++){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int pop(){
//         if (s1.size() == 0) {
//             cout<<"Queue is Empty"<<endl;
//             return -1;
//         }
//         int poppedValue = s1.top();
//         s1.pop();
//         return poppedValue;
//     }

//     int peek(){
//          if (s1.size() == 0) {
//             cout<<"Queue is Empty"<<endl;
//             return -1;
//         }
//         return s1.top();
//     }

//     int size(){
//         return s1.size();
//     }

//     bool isEmpty(){
//         return s1.size() == 0;
//     }
// };

// int main(){
//     Queue q;
//     q.push(10);
//     cout<<q.peek()<<endl;
//     q.push(20);
//     cout<<q.peek()<<endl;
//     q.push(30);
//     cout<<q.peek()<<endl;
//     cout<<q.size()<<endl;
//     cout<<q.isEmpty()<<endl;
//     cout<<q.pop()<<endl;
//     cout<<q.pop()<<endl;
//     cout<<q.pop()<<endl;
//     cout<<q.pop()<<endl;
//     cout<<q.peek()<<endl;
//     return 0;
// }




// use when push > pop, peek
class Queue {
    stack <int> s1;
    stack <int> s2;

    public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if (!s2.empty()){
            int poppedValue = s2.top();
            s2.pop();
            return poppedValue;
        }else{
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int poppedValue = s2.top();
            s2.pop();
            return poppedValue;
        }
    }

    int peek(){
        if (!s2.empty()){
            return s2.top();
        }else{
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }

    int size(){
        return s1.size() + s2.size();
    }

    bool isEmpty(){
        return s1.size() == 0;
    }
};


int main(){
    Queue q;
    q.push(10);
    cout<<q.peek()<<endl;
    q.push(20);
    cout<<q.peek()<<endl;
    q.push(30);
    cout<<q.peek()<<endl;
    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    return 0;
}