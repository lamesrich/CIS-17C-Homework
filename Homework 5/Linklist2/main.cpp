#include <iostream>
#include <cstdlib>
#include "Linklist.h"

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    LnkdLst a(100);
    //LnkdLst a;
    a.prepend(1000);
    a.prepend(211);
    a.prepend(2222);
    a.prepend(1234);
    a.append(111);
    a.pop_fornt();
    a.pop_fornt();
    a.display();
    cout << a.sz() << endl;
    a.InsertAfter(3, 222);
    a.display();
    a.InsertAfter(3,234);
    a.display();
    a.InsertBefore(1, 143);
    a.display();
    a.InsertBefore(4, 700);
    a.display();
    return 0;
}