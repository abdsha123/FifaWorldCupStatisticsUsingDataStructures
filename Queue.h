#pragma once
#include<iostream>

using namespace std;

struct QNode
{
    float data;
    string team;
    struct QNode* prev;
    struct QNode* next;

    QNode()
    {
        float data;
        string team;
        struct QNode* prev = NULL;
        struct QNode* next = NULL;

    }
    QNode(float value, string T)
    {

        data = value;
        team = T;
        prev = NULL;
        next = NULL;

    }
};
class Queue
{
    struct QNode* front;
    struct QNode* rear;
    int Size;


public:
    Queue();
    float getRear();
    float getFront();
    bool isFull();
    bool isEmpty();
    void insertAtFront(float data,string team);
    void insertAtRear(float data, string team);
    void displayRear();
    void displayFront();


};

Queue::Queue()
{
    
    struct QNode* front=NULL ;
    struct QNode* rear=NULL ;
    Size = 0;

}

bool Queue::isEmpty()
{
    return Size == 0;
}

bool Queue::isFull()
{
    struct QNode* n = new QNode();
    if (n == NULL)
    {
        return 1;
    }

    else

        return 0;
}
// Function to insert an element at the beginning of the deque.
void Queue::insertAtFront(float data, string team) {

    

        struct QNode* newNode = new QNode(data, team);
    
    // If deque is empty then update the front and rear pointers.
    if (front==NULL) {
        rear = front = newNode;
    }
    // Otherwise insert at the beginning of the deque according to the algorithm described above.
    else
    {
        newNode->next =  front;
        front->prev = newNode;
        front = newNode;
    }

    // Increase the size of the queue by one.
    Size++;
}


// Function to insert an element at the end of the deque.
void Queue::insertAtRear(float data, string team)
{
    struct QNode* newNode = new QNode(data, team);
        // If deque is empty then update the front and rear pointers.
        if (rear == NULL)

        {
              front = rear = newNode;
        }
        // Otherwise insert at the end of the deque according to the algorithm described above.
        else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;

        }
        // Increase the size of the queue by one.
        Size++;
    
}

float Queue::getFront() {
  
        if (!isEmpty())
        {
            
            return front->data;
            
        }
       

}

float Queue::getRear() {

    if (!isEmpty())
    {

        
        return rear->data;
    }
}

void Queue::displayFront()
{

    cout << front->data << " " << front->team << endl;
}


void Queue::displayRear()
{

    cout << rear->data << " " << rear->team << endl;
}

