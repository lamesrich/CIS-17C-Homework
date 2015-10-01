#include <iostream>
#include <cstdlib>
#include "Linklist.h"

using namespace std;

LnkdLst :: LnkdLst()
{
    head = 0;
    tail = 0;
    size = 0;
}
LnkdLst :: LnkdLst(LnkdLst *temp)
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
LnkdLst :: LnkdLst(int value)
{
    Node *temp = new Node;
    temp -> data = value;
    temp -> next = 0;
    head = temp;
    tail = temp;
    size = 1;
}
void LnkdLst :: extract(int value)
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
LnkdLst :: ~LnkdLst()
{
    while(head != 0)
    {
        pop_fornt();
    }
}
int LnkdLst :: first()
{
    return head -> data;
}
int LnkdLst :: last()
{
    return tail -> data;
}
void LnkdLst :: pop_fornt()
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
void LnkdLst :: InsertAfter(int index, int value)
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
void LnkdLst :: InsertBefore(int index, int value)
{
    if(index == 1) prepend(value);
    else InsertBefore(index - 1, value);
}
void LnkdLst :: append(int value)
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

void LnkdLst :: prepend(int value)
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
void LnkdLst :: display() const
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
int LnkdLst ::sz() const
{
    return size;
}