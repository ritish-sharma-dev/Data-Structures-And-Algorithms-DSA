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

class Queue {
    Node* start;
    Node* end;
    int currSize;

    public:
    Queue(){
        start = NULL;
        end = NULL;
        currSize = 0;
    }

    void push(int x){
        Node* newNode = new Node(x);
        if (currSize == 0) {
            start = newNode;
            end = newNode;
        }else{
            end->next = newNode;
            end = newNode;
        }
        currSize++;
    }

    int pop(){
        if (currSize == 0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        Node* poppedNode = start;
        int poppedNodeValue = start->data;
        if (currSize == 1) start = NULL, end = NULL;
        else start = start->next;
        delete poppedNode;
        currSize--;
        return poppedNodeValue;
    }

    int peek(){
        if (currSize == 0) {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return start->data;
    }

    int size(){
        return currSize;
    }

    bool isEmpty(){
        return currSize == 0;
    }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.size()<<endl;
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.size()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}