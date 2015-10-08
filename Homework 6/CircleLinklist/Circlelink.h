#ifndef LNKDLST_H
#define	LNKDLST_H

#include <string>
#include <iostream>

using namespace std;


template<class T>
class LnkdLst 
{
    public:
        LnkdLst();
        LnkdLst(LnkdLst *);
        T first();
        T last();
        LnkdLst(T value);
        void InsertAfter(int index, T value);
        void InsertBefore(int index, T value);
        void append(T value);
        void prepend(T value);
        void pop_fornt();
        void display() const;
        int sz() const;
        //string toString();
        ~LnkdLst();
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
LnkdLst<T> :: LnkdLst()
{
    head = 0;
    tail = 0;
    size = 0;
}
template<class T>
LnkdLst<T> :: LnkdLst(LnkdLst *temp)
{
    if(temp -> head == 0) return;
    size = 0;
    Node *curr = temp -> head;
    do
    {
        this -> append(curr -> data);
        curr = curr -> next;
        
    }while(curr -> next != 0);
    tail -> next = head;
}
template<class T>
LnkdLst<T> :: LnkdLst(T value)
{
    Node *temp = new Node;
    temp -> data = value;
    temp -> next = 0;
    head = temp;
    tail = temp;
    size = 1;
    tail -> next = head;
}

template<class T>
LnkdLst<T> :: ~LnkdLst()
{
    while(head != 0)
    {
        pop_fornt();
    }
}
template<class T>
T LnkdLst<T> :: first()
{
    return head -> data;
}
template<class T>
T LnkdLst<T> :: last()
{
    return tail -> data;
}
template<class T>
void LnkdLst<T> :: pop_fornt()
{
    if(head == 0) 
    {
        return;
    }
    Node *temp = head;
    head = head -> next;
    delete temp;
    tail -> next = head;
    if(head == 0)
    {
        tail = 0;
    }
    tail -> next = head;
    size--;
}
template<class T>
void LnkdLst<T> :: append(T value)
{
    Node *temp = new Node;
    temp -> data = value;
    if(head == 0)
    {
        temp -> next = 0;
        head = temp;
        tail = temp;
        tail -> next = head;
        return;
    }
    tail -> next = temp;
    temp -> next = 0;
    tail = temp;
    tail -> next = head;
    size++;
}
template<class T>
void LnkdLst<T> :: prepend(T value)
{
    Node *temp = new Node;
    temp -> data = value;
    if(head == 0)
    {
        temp -> next = 0;
        head = temp;
        tail = temp;
        return;
    }
    temp -> next = head;
    head = temp;
    if(temp -> next == 0) tail = temp;
    size++;
}
template<class T>
void LnkdLst<T> :: display() const
{
    if(head == 0) return;
    Node *temp = head;
    cout << temp -> data << " ";
    do
    {
        temp = temp -> next;
        cout << temp -> data << " ";
    }while(temp -> next != head);
    cout << endl;
}
template<class T>
int LnkdLst<T> ::sz() const
{
    return size;
}
#endif	/* LNKDLST_H */