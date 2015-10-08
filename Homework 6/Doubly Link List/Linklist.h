//
//  Linklist.h
//  Doubly Linklist
//
//  Created by William Sun on 10/7/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#ifndef Linklist_h
#define Linklist_h
#include <iostream>
#include <cstdlib>

using namespace std;


template<class T>
class Linklist
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        
    };
    Node *head;
    Node *tail;
public:
    Linklist();
    Linklist(T);
    void push_back(T);
    void pop_front();
    void display();
};


template<class T>
Linklist<T> :: Linklist()
{
    head = 0;
    tail = 0;
}

template<class T>
Linklist<T> :: Linklist(T value)
{
    Node *temp = new Node;
    temp -> next = 0;
    temp -> prev = 0;
    temp -> data = value;
    head = temp;
    tail = temp;
}

template<class T>
void Linklist<T> :: push_back(T value)
{
    Node *temp = new Node;
    temp -> data = value;
    if(head == 0)
    {
        //cout << "a" << endl;
        temp -> next = 0;
        //cout << "b" << endl;
        temp -> prev = 0;
        //cout << "c" << endl;
        head = temp;
        //cout << "d" << endl;
        tail = temp;
        //cout << "e" << endl;
        return;
    }
    tail -> next = temp;
    temp -> prev = tail;
    temp -> next = 0;
    tail = temp;
}

template<class T>
void Linklist<T> :: pop_front()
{
    cout << "pop_front called" << endl;
    if(head == 0) return;
    Node *temp = head;
    head = head -> next;
    if(head == 0)
    {
        tail = 0;
        return;
    }
    head -> prev = 0;
    delete temp;
   
}

template<class T>
void Linklist<T> :: display()
{
    if(head == 0)
    {
        cout << "Nothing" << endl;
        return;
        
    }
    Node *temp = head;
    cout << temp -> data << " ";
    while(temp != tail)
    {
        
        temp = temp -> next;
        cout << temp -> data << " ";
    }
    cout << endl;
}

#endif /* Linklist_h */
