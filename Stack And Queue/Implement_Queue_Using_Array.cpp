#include <iostream>
using namespace std;

class Queue {
    private:
    int capacity;
    int* queueArray;
    int start;
    int end;
    int currSize;

    public:
    Queue(int capacity){
        this->capacity = capacity;
        queueArray = new int[capacity];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int value){
        if (currSize >= capacity) {
            cout<<"Queue Overflow"<<endl;
            return;
        } 
        if (currSize == 0) start=0, end = 0;
        else end = (end+1)%capacity;
        queueArray[end] = value;
        currSize++;
    }

    int pop(){
        if (currSize == 0) {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        int popped = queueArray[start];
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else start = (start+1)%capacity;
        currSize--;
        return popped;

    }

    int top(){
        if (currSize == 0) {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return queueArray[start];
    }

    int size(){
        return currSize;
    }

    bool isEmpty(){
        return currSize == 0;
    }
};


int main(){
    Queue q(4);
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    // q.push(30);
    cout<<q.top()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;
    return 0;
}