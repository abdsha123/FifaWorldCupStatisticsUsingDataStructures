#pragma once
#include<iostream>
using namespace std;


class Stack
{
    int size;
    int top;
    float arr[32];

public:
    Stack();
    void push(float);
    float pop();
    bool isFull();
    bool isEmpty();
    float stackTop();
    float stackBottom();

};

Stack::Stack()
{
    size = 32;
    
    top = -1;
}

bool Stack:: isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
        return top=size-1;
 }

void Stack::push(float data) {
 
        arr[++top] = data;
    }


float Stack::pop() {
    return arr[top--];
    }


float Stack::stackTop() {
    return arr[top];
}

float Stack::stackBottom() {
    return arr[0];
}
