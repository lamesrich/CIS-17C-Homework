//
//  main.cpp
//  No.2
//
//  Created by Zexi Sun on 10/28/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//
//  Fill a vector with random inputs.  Write a function
//  vector *mode(vector x) that returns a vector that
//  represents the mode of vector x.  Note:  Make sure
//  there is more than one mode.

#include <cstdlib>
#include <map>
#include <vector>
#include <ctime>
#include <iostream>
#include <algorithm>
#include "Vector.h"

using namespace std;



// functions
void fillVector(Vector<int> &, unsigned);
vector<pair<int, int>> countMode(Vector<int> &, unsigned);
bool cmp_by_value(const pair<int, int> &, const pair<int, int> &);

int main()
{
    srand((unsigned)time(0));
    Vector<int> a;
    unsigned size = 1000;
    fillVector(a, size);
    a.print();
    cout << endl;
    
    //print frequency
    cout << endl;
    //cout << "Key and Frequency" << endl;
    
    vector<pair<int, int>> result = countMode(a, size);
    cout << endl;

    
    
//    for(unsigned i = 0; i < result -> size(); i++)
//    {
//        cout << result -> at(i).first << "  " << result -> at(i).second << endl;
//    }
//    
    
    return 0;
}

// find mode; and put each mode number in a new my own Vector.
// Will show the frequency of each value.
// Return that Vector

vector<pair<int, int>> countMode(Vector<int> &a, unsigned size)
//void countMode(Vector<int> &a, unsigned size)
{
    vector<pair<int, int>> temp;
    map<int, int> key;
    map<int, int> :: iterator key_lter;
    
    
    
    int curr = 0;
    int count;
    for(unsigned i = 0; i < size; i++)
    {
        curr = a.at(i);
        count = 1;
        while(i < size - 1 && curr == a.at(i + 1))
        {
            i++;
            count++;
        }
        key.insert(pair<int, int> (curr, count));
        
        
    }
    if(a.at(size - 2) != a.at(size - 1)) key.insert(pair<int, int>(a.at(size - 1), 1));
    
    
    
    //cout << "Hello World" << endl;
    // print the frequency
    cout << "Key Frequency(Unsorted)" << endl;
    for(key_lter = key.begin(); key_lter != key.end(); key_lter++)
    {
        cout << key_lter -> first << " " << key_lter -> second << endl;
    }
    cout << endl << endl;
    
    cout << "Key Frequency(Sorted)" << endl;
    vector<pair<int, int>> mode(key.begin(), key.end());
    sort(mode.begin(), mode.end(), cmp_by_value);
    for(unsigned i = 0; i < mode.size(); i++)
    {
        cout << mode.at(i).first << " " << mode.at(i).second << endl;
    }
    
    cout << endl << endl;
    temp.push_back(mode.at(0));
    unsigned i = 1;
    while(mode.at(i).second == mode.at(i - 1).second)
    {
        temp.push_back(mode.at(i));
        if(i == size - 1) break;
        else i++;
        
    }
    cout << "The Mode is " << endl;
    for(unsigned i = 0; i < temp.size(); i++)
    {
        cout << temp.at(i).first << "  " << temp.at(i).second << endl;
    }
    return temp;

}


// Vector will be filled and sorted
// in this function.

void fillVector(Vector<int> &a, unsigned size)
{
    vector<int> temp;
    for(unsigned i = 0; i < size; i++)
    {
        temp.push_back((rand() % 11));
    }
    sort(temp.begin(), temp.end());
    for (unsigned i = 0; i < size; i++)
    {
        a.push_back(temp.at(i));
    }
}

bool cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
    return lhs.second > rhs.second;
}