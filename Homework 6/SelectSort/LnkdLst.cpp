#include <iostream>
#include <cstdlib>
#include "LnkdLst.h"

using namespace std;

LnkdLst :: LnkdLst()
{
    head = 0;
    tail = 0;
}
LnkdLst :: LnkdLst(int value)
{
    Node *temp = new Node;
    temp -> data = value;
    temp -> next = 0;
    head = temp;
    tail = temp;
}
LnkdLst :: ~LnkdLst()
{
    while(head != 0)
    {
        pop_fornt();
    }
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

void LnkdLst :: find(int value)
{
    if(head == 0) return;
    Node *temp = head;
    Node * curr = head -> next;
    while(curr != 0)
    {
        if(curr -> data == value)
        {
            cout << "find match" << endl;
            temp -> next = curr -> next;
            curr -> next = head;
            head = curr;
            return;
        }
        temp = temp -> next;
        curr = curr -> next;
    }
    cout << "Did not find match" << endl; 
    
    
}
void LnkdLst :: select_sort()
{
    if(head == 0)
        return;
    Node *curr;
    Node *temp;
    for(curr = head; curr != 0; curr = curr -> next)
    {
        for(temp = curr -> next; temp != 0; temp = temp -> next)
        {
            if((curr -> data) > (temp -> data))
            {
                swap((curr -> data), (temp -> data));
            }

        }
    }
}