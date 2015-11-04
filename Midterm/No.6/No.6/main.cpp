//
//  main.cpp
//  Problem 6
//
//  Created by Zexi Sun on 11/2/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

//
//  List   - Fill a list with random inputs.  Write a function
//           statClass *stat(vector x) that returns a class that
//           contains the min,max and average of the x vector but
//           also uses a map to solve the mode problem and returns
//           the important elements for the mode.

#include <ctime>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include "List.h"
#include "FrequencyList.h"
#include "StatClass.h"

void fillList(List<int> &, int);
FrequencyList mode(List<int> &x);
bool cmp_by_value(const pair<int, int> &, const pair<int, int> &);
StatClass stat(List<int> &);

using namespace std;


int main()
{
    srand((unsigned)(time(0)));
    int size = 100;
    List<int> a;
    fillList(a, size);
    a.display();
    cout << endl;
    FrequencyList result = mode(a);
    result.print();
    StatClass ImportantValue = stat(a);
    ImportantValue.print();
    
    return 0;
}
StatClass stat(List<int> &x)
{
    int max = x.List :: first();
    int min = x.List :: last();
    int total = x.List :: getTotal();
    
    StatClass result(max, min, total);
    return result;
}



bool cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
    return lhs.second > rhs.second;
}
FrequencyList mode(List<int> &x)
{
    map<int, int> frequency;
    frequency = x. List :: frequency();
    vector<pair<int, int>> key(frequency.begin(), frequency.end());
    sort(key.begin(), key.end(), cmp_by_value);
    cout << "Sorted Frequency" << endl;
    for(unsigned i = 0; i < key.size(); i++)
    {
        cout << key.at(i).first << "  " << key.at(i).second << endl;
    }
    
    FrequencyList mode(key);
    
    
    
    
    return mode;
}

void fillList(List<int> &a, int size)
{
    for(int i = 0; i < size; i++)
    {
        a.List :: append(rand() % 11);
        
    }
    a.List :: sort();
    
}