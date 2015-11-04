//
//  List.hpp
//  No.4
//
//  Created by Zexi Sun on 11/1/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#ifndef List_H
#define	List_H

#include <string>
#include <map>
#include <iostream>

using namespace std;


template<class T>
class List
{
public:
    List();
    List(List *);
    T first();
    T last();
    void sort();
    map<int, int> frequency();
    List(T value);
    void extract(T value);
    void InsertAfter(int index, T value);
    void InsertBefore(int index, T value);
    void append(T value);
    void prepend(T value);
    void pop_fornt();
    void display() const;
    int sz() const;
    //string toString();
    ~List();
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
void List<T> :: sort()
{
    Node *temp = new Node;
    Node *curr = new Node;
    for(temp = head; temp != 0; temp = temp -> next)
    {
        for(curr = temp -> next; curr != 0; curr = curr -> next)
        {
            if((temp -> data) > (curr -> data))
            {
                swap((temp -> data), (curr -> data));
//                int temporate = curr -> data;
//                curr -> data = temp -> data;
//                temp -> data = temporate;
            }
        }
    }
}


// Frequency has be called after sort function
template<class T>
map<int, int> List<T> :: frequency()
{
    map<int, int> frequency;
    map<int, int> :: iterator it;
    int count = 1;
    Node *temp = new Node;
    Node *curr = new Node;
    for(temp = head; temp != 0; temp = temp -> next)
    {
        count = 1;
        for(curr = temp -> next; curr != 0; curr = curr -> next)
        {
            if(temp -> data == curr -> data)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        frequency.insert(pair<int, int>(temp -> data, count));
        
    }
    // output frequency
    cout << "Key Frequency" << endl;
    for(it = frequency.begin(); it != frequency.end(); it++)
    {
        cout << it -> first << " " << it -> second << endl;
    }
    return frequency;
    
    
}
template<class T>
List<T> :: List()
{
    head = 0;
    tail = 0;
    size = 0;
}
template<class T>
List<T> :: List(List *temp)
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
List<T> :: List(T value)
{
    Node *temp = new Node;
    temp -> data = value;
    temp -> next = 0;
    head = temp;
    tail = temp;
    size = 1;
}
template<class T>
void List<T> :: extract(T value)
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
List<T> :: ~List()
{
    while(head != 0)
    {
        pop_fornt();
    }
}
template<class T>
T List<T> :: first()
{
    return head -> data;
}
template<class T>
T List<T> :: last()
{
    return tail -> data;
}
template<class T>
void List<T> :: pop_fornt()
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
void List<T> :: InsertAfter(int index, T value)
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
void List<T> :: InsertBefore(int index, T value)
{
    if(index == 1) prepend(value);
    else InsertBefore(index - 1, value);
}
template<class T>
void List<T> :: append(T value)
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
void List<T> :: prepend(T value)
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
void List<T> :: display() const
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
int List<T> ::sz() const
{
    return size;
}
#endif	/* List_H */