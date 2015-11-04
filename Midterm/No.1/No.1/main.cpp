//
//  main.cpp
//  No.1
//
//  Created by Zexi Sun on 10/28/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//


//  1)  Vector - Fill a vector with random inputs.  Write a function
//  vector *top(vector x,int p) that returns in a
//  vector the top p elements of the x input vector.


#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <algorithm>
#include <vector>
#include "Vector.h"

using namespace std;

void fillVector(Vector<int> &, unsigned);
vector<int> *top(vector<int> &, int);
void sort(vector<int> &);
Vector<int> *top(Vector<int> &, unsigned p);

int main()
{
    
    srand((unsigned)time(0));
    unsigned size = 100;
    Vector<int> a;
    fillVector(a, size);
    cout << "The original Vector" << endl;
    a.print();
    a.sort();
    cout << endl;
    cout << "Sorted Vector" << endl;
    a.print();
    Vector<int> *result = top(a, 10);
    
    cout << endl;
    cout << "The top 10 elements" << endl;

    result -> print();
}

void fillVector(Vector<int> &a, unsigned size)
{
    for(unsigned i = 0; i < size; i++)
    {
        a.push_back((rand() % 101));
    }
}

Vector<int> *top(Vector<int> &a, unsigned p)
{
    Vector<int> *temp = new Vector<int>;
    for(unsigned i = 0; i < p; i++)
    {
        temp -> push_back(a.at(i));
    }
    return temp;
    
}