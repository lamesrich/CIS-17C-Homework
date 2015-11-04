//
//  ScoreList.cpp
//  Grade_System
//
//  Created by William Sun on 10/20/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#include "ScoreList.h"
#include <iostream>
#include <vector>
using namespace std;

ScoreList :: ScoreList()
{
    head = 0;
    tail = 0;
}
ScoreList :: ScoreList(string name, int math, int english, int science)
{
    Node *temp = new Node;
    temp -> Name = name;
    temp -> score.push_back(math);
    temp -> score.push_back(english);
    temp -> score.push_back(science);
    temp -> score.push_back(math + english + science);
    
    temp -> next = 0;
    head = temp;
    tail = temp;
}
ScoreList :: ScoreList(const ScoreList &rhs)
{
    head = 0;
    tail = 0;
    string name;
    int math;
    int english;
    int science;
    for(Node *temp = rhs.head; temp != 0; temp = temp -> next)
    {
        name = temp -> Name;
        math = temp -> score.at(0);
        english = temp -> score.at(1);
        science = temp -> score.at(2);
        addScore(name, math, english, science);
        
    }
    
    
}


void ScoreList :: addScore(string name, int math, int english, int science)
{
    
    Node *temp = new Node;
    temp -> Name = name;
    temp -> score.push_back(math);
    temp -> score.push_back(english);
    temp -> score.push_back(science);
    int total = math + english + science;
    temp -> score.push_back(total);
    
    temp -> next = 0;
    if(head == 0)
    {
        head = temp;
        tail = temp;
        return;
    }

    temp -> next = 0;
    tail -> next = temp;
    tail = temp;
}

void ScoreList :: DisplayScores()
{
    cout << "Students Socres" << endl;
    cout << "Ranks   Name   Math    English    Science     Total" << endl;
    int i = 1;
    Node *temp = head;
    do
    {
        cout << i << "       " << temp -> Name << "    " << temp -> score.at(0) << "     " << temp -> score.at(1) << "          " << temp -> score.at(2) << "         " << temp -> score.at(3) << endl;
        i++;
        temp = temp -> next;
    }while(temp != 0);
    
}
void ScoreList :: sort()
{
    for(Node *temp = head; temp != 0; temp = temp -> next)
    {
        for(Node *curr = temp -> next; curr != 0; curr = curr -> next)
        {
            if(temp -> score.at(3) < curr -> score.at(3))
            {
                swap(temp -> Name, curr -> Name);
                swap(temp -> score, curr -> score);
            }
        }
    }
}