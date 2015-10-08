//
//  main.cpp
//  Doubly Linklist
//
//  Created by William Sun on 10/7/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#include <iostream>
#include "Linklist.h"

using namespace std;


int main()
{
    
    cout << "Hello World" << endl;
    Linklist<int> a;
    a.push_back(12);
    a.push_back(32);
    a.display();
    a.pop_front();
    a.display();
    a.pop_front();
    a.display();
    return 0;
}
