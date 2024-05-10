#include <iostream>

using namespace std;

template <class T>

class ListNode {   //classs definition of Node 
public:
    T data;
    ListNode* next;
    ListNode(T data);
    
};
template <class T>
ListNode<T>::ListNode(T data)
{
    next = NULL;
    this->data = data;
}


//PASTE YOUR LINKED LIST CODE HERE
template <class T>
class LinkedList {
    
public:
    ListNode<T>* current, * start;
    LinkedList();
    void insert(T data);
 
    
    
};
template <class T>
LinkedList<T>::LinkedList() {
    current = start = NULL;
 
}

template <class T>
void LinkedList<T>::insert(T data) {

    ListNode<T>* n = new ListNode<T>(data);

    if (start == NULL) {
        start= n;
        current= n;

    }
    else {
        current->next = n;
        current = n;

    }
}







