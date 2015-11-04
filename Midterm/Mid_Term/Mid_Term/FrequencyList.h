//
//  FrequencyList.h
//  No.5
//
//  Created by Zexi Sun on 11/2/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#ifndef FrequencyList_h
#define FrequencyList_h

#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

using namespace std;

struct Node
{
    int key;
    int frequency;
    Node *next;
};


class FrequencyList
{
private:
    Node *head;
    Node *tail;
public:
    FrequencyList();
    FrequencyList(vector<pair<int, int> >);
    void push_back(int, int);
    void print();
    
    
};

FrequencyList :: FrequencyList()
{
    head = 0;
    tail = 0;
}

FrequencyList :: FrequencyList(vector<pair<int, int> > a)
{
    Node *temp = new Node;
    temp -> key = a.at(0).first;
    temp -> frequency = a.at(0).second;
    temp -> next = 0;
    head = temp;
    tail = temp;
    for(unsigned i = 1; i < a.size(); i++)
    {
        if(a.at(0).second == a.at(i).second)
        {
            push_back(a.at(i).first, a.at(i).second);
        }
        else break;
    }
}
void FrequencyList :: print()
{
    cout << "The mode are/is " << endl;
    cout << "Key  Frequency" << endl;
    for(Node *temp = head; temp != 0; temp = temp -> next)
    {
        cout << temp -> key << "   " << temp -> frequency << endl;
    }
}

void FrequencyList :: push_back(int key, int frequency)
{
    Node *temp = new Node;
    temp -> key = key;
    temp -> frequency = frequency;
    temp -> next = 0;
    if(head == 0)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail -> next = temp;
    tail = temp;
}



#endif /* FrequencyList_h */
