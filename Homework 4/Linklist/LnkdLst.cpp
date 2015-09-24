#include <iostream>
#include <cstdlib>
#include "LnkdLst.h"

using namespace std;

LnkdLst :: LnkdLst()
{
    head = 0;
    worker = 0;
}
LnkdLst :: LnkdLst(int value)
{
    Node *temp = new Node;
    temp -> data = value;
    temp -> next = 0;
    head = temp;
    worker = temp;
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
        worker = 0;
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
        worker = temp;
        return;
    }
    worker -> next = temp;
    temp -> next = 0;
    worker = temp;
}

void LnkdLst :: prepend(int value)
{
    Node *temp = new Node;
    temp -> data = value;
    if(head == 0)
    {
        temp -> next = 0;
        head = temp;
        worker = temp;
        return;
    }
    temp -> next = head;
    head = temp;
    if(temp -> next == 0) worker = temp;
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