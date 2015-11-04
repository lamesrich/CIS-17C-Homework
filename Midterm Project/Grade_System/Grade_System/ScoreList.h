//
//  ScoreList.hpp
//  Grade_System
//
//  Created by William Sun on 10/20/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#ifndef ScoreList_hpp
#define ScoreList_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    string Name;
    unsigned ranks;
    vector<int> score;
    
    Node *next;
};

class ScoreList
{
    private:
        Node *head;
        Node *tail;
    public:
        ScoreList();
        ScoreList(string, int, int, int);
        ScoreList( const ScoreList &);
    
    
        void sort();
        void addScore(string, int, int, int);
        void DisplayScores();
        
    

};
#endif /* ScoreList_hpp */
