#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

// class Stack {
//     Node* head;
//     Node* top;
//     int currSize;

//     public:
//     Stack(){
//         head = NULL;
//         top = NULL;
//         currSize = 0;
//     }

//     void push(int x){
//         Node* newNode = new Node(x);
//         if (currSize == 0){
//             head = newNode;
//             top = newNode;
//         }else{
//             top->next = newNode;
//             top = newNode;
//         }
//         currSize++;
//     }

//     int pop(){
//         if (currSize == 0) {
//             cout<<"Stack is Empty"<<endl;
//             return -1;
//         }
//         int poppedNodeValue = top->data;
//         Node* poppedNode = top;
//         if (currSize == 1){
//             head = NULL;
//             top = NULL;
//         }else{
//             Node* temp = head;
//             while (temp->next != top){
//                 temp = temp->next;
//             }
//             temp->next = NULL;
//             top = temp;
//         }
//         currSize--;
//         delete poppedNode;
//         return poppedNodeValue;
//     }

//     int peek(){
//         if (currSize == 0) {
//             cout<<"Stack is Empty"<<endl;
//             return -1;
//         }
//         return top->data;
//     }

//     int size(){
//         return currSize;
//     }

//     bool isEmpty(){
//         return currSize == 0;
//     }
// };

// int main(){
//     Stack s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     cout<<s.peek()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.pop()<<endl;
//     cout<<s.peek()<<endl;
//     cout<<s.size()<<endl;
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.push(60);
//     s.push(70);
//     cout<<s.pop()<<endl;
//     cout<<s.peek()<<endl;
//     cout<<s.size()<<endl;
//     cout<<s.isEmpty()<<endl;
//     return 0;
// }



class Stack {
    Node* top;
    int currSize;

    public:
    Stack(){
        top = NULL;
        currSize = 0;
    }

    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        currSize++;
    }

    int pop(){
        if (currSize == 0) {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        int poppedNodeValue = top->data;
        Node* poppedNode = top;
        top = top->next;
        delete poppedNode;
        currSize--;
        return poppedNodeValue;
    }

    int peek(){
        if (currSize == 0) {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return top->data;
    }

    int size(){
        return currSize;
    }

    bool isEmpty(){
        return currSize == 0;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.size()<<endl;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}