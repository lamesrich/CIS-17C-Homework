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
        void extract(T value);
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
}
template<class T>
void LnkdLst<T> :: extract(T value)
{
    if(this -> head == 0) return;
    Node *temp = head;
    Node *curr = head -> next;
    do
    {
        if(temp -> data == value)
        {
            curr -> next = temp -> next;
            delete temp;
            temp = curr -> next;
            size--;
        }
        else
        {
            temp = temp -> next;
            curr = curr -> next;
        }
    }while(temp -> next != 0);
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
    if(head == 0)
    {
        tail = 0;
    }
    size--;
}
template<class T>
void LnkdLst<T> :: InsertAfter(int index, T value)
{
    if(index > size + 1) return;
    if(head == 0)
    {
        append(value);
        return;
    }
    if(index == size) 
    {
        append(value);
        return;
    }
    Node *temp = head;
    Node *curr = head -> next;
    Node *curr1 = new Node;
    curr1 -> data = value;
    if(index == size - 1)
    {
        do
        {
            temp = temp -> next;
            curr = curr -> next;
        }while(curr -> next != 0);
        temp -> next = curr1;
        curr1 -> next = curr;
        size++;
        return;
    }
    int count = 1;
    while(count != index)
    {
        temp = temp -> next;
        curr = curr -> next;
        count++;
    }
    temp -> next = curr1;
    curr1 -> next = curr;
    size++;
    
    
}
template<class T>
void LnkdLst<T> :: InsertBefore(int index, T value)
{
    if(index == 1) prepend(value);
    else InsertBefore(index - 1, value);
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
        return;
    }
    tail -> next = temp;
    temp -> next = 0;
    tail = temp;
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
    }while(temp -> next != 0);
    cout << endl;
}
template<class T>
int LnkdLst<T> ::sz() const
{
    return size;
}
#endif	/* LNKDLST_H */