//
//  main.cpp
//  No.4
//
//  Created by Zexi Sun on 10/31/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//



//  4)  List - Fill a vector with random inputs.  Write a function
//               vector *top(vector x,int p) that returns in a
//               vector the top p elements of the x input vector.
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "List.h"

void fillList(List<int> &, int);
List<int> *top(List<int>, int);

using namespace std;

int main(int argc, const char * argv[])
{
    srand((unsigned)(time(0)));
    int size = 100;
    List<int> a;
    fillList(a, size);
    a.display();
    cout << endl;
    cout << "The top 10 elements are: ";
    List<int> *result;
    result = top(a, 10);
    result -> display();
    
    return 0;
}

List<int> *top(List<int> a, int p)
{
    List<int> *result = new List<int>;
    for(int i = 0; i < p; i++)
    {
        result -> append(a.first());
        a.pop_fornt();
    }
    return result;
}

// fill the list
// and sort the list
void fillList(List<int> &a, int size)
{
    for(int i = 0; i < size; i++)
    {
        a.List :: append(rand() % 51);

    }
    a.List :: sort();
    
}