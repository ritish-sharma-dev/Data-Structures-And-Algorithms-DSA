// C++ CODE
#include <iostream>
using namespace std;

class Stack {
    private:
    int capacity;
    int* stackArray;
    int topIndex;

    public:
    Stack(int capacity){
        this->capacity = capacity;
        stackArray = new int[capacity];
        topIndex = -1;
    }

    void push(int value){
        if (topIndex >= capacity-1) {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        stackArray[++topIndex] = value;
    }

    int pop(){
        if (topIndex == -1) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return stackArray[topIndex--];
    }

    int top(){
        if (topIndex == -1) {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return stackArray[topIndex];
    }

    int size(){
        return topIndex+1;
    }

    bool isEmpty(){
        return topIndex == -1;
    }
};

int main(){
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.top()<<" ";
    s.pop();
    s.pop();
    cout<<s.top()<<" ";
    s.pop();
    s.pop();
    cout<<s.top()<<" ";
    cout<<s.size()<<" ";
    s.push(90);
    cout<<s.top()<<" ";
    s.pop();
    cout<<s.size()<<" ";
    s.pop();
    cout<<s.isEmpty()<<" ";
}




// JAVA CODE
import java.lang.*;
import java.util.*;

class Stack {
    private int capacity;
    private int []stackArray;
    private int topIndex;

    public Stack(int capacity){
        this.capacity = capacity;
        stackArray = new int[capacity];
        topIndex = -1;
    }

    public void push(int value){
        if (topIndex >= capacity-1) {
            System.out.println("Stack Overflow");
            return;
        }
        stackArray[++topIndex] = value;
    }

    public int pop(){
        if (topIndex == -1) {
            System.out.println("Stack is empty");
            return -1;
        }
        return stackArray[topIndex--];
    }

    public int peek(){
        if (topIndex == -1){
            System.out.println("Stack is empty");
            return -1;
        }
        return stackArray[topIndex];
    }

    public int size(){
        return topIndex+1;
    }

    public boolean empty(){
        return topIndex == -1;
    }
}

public class Main {
    public static void main(String[] args){
        Stack s = new Stack(10);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        System.out.print(s.peek() + " ");
        s.pop();
        s.pop();
        System.out.print(s.peek() + " ");
        s.pop();
        s.pop();
        System.out.print(s.peek() + " ");
        System.out.print(s.size() + " ");
        s.push(90);
        System.out.print(s.peek() + " ");
        s.pop();
        System.out.print(s.size() + " ");
        s.pop();
        System.out.print(s.empty() + " ");
    }
}