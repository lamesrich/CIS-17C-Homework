#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
#include <iostream>

using namespace std;


template<class T>
class Queue 
{
    public:
        Queue();
        Queue(T);
        void append(T);
        void prepend();
    private:
        struct Node
        {
            T data;
            Node *next;
        };
        int size;
        Node *head;
        Node *tail;
};
template<class T>
Queue<T> :: Queue()
{
    head = 0;
    tail = 0;
}
template<class T>
Queue<T> :: Queue(T value)
{
    Node *temp = new Node;
    temp -> data = value;
    temp -> next = 0;
    head = temp;
    tail = temp;
}

template<class T>
void Queue<T> :: append(T value)
{
    if(head == 0) 
    {
        Node *temp = new Node;
        temp -> data = value;
        temp -> next = 0;
        head = temp;
        tail = temp;
        return;
    }
    Node *temp = new Node;
    temp -> data = value;
    temp -> next = 0;
    tail -> next = temp;
}

template<class T>
void Queue<T> :: prepend()
{
    if(head == 0) return;
    Node *temp = head;
    head = head -> next;
    delete temp;
    if(head == 0)
    {
        tail = 0;
    }
}
#endif	/* LNKDLST_H */