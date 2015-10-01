#include <iostream>
#include <cstdlib>
#include "Linklist.h"

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    LnkdLst<float> a(100.3);
    //LnkdLst a;
    a.prepend(1000.3);
    a.prepend(211.3);
    a.prepend(2222.3);
    a.prepend(1234.3);
    a.append(111.3);
    a.pop_fornt();
    a.pop_fornt();
    a.display();
    cout << a.sz() << endl;
    a.InsertAfter(3, 222.33);
    a.display();
    a.InsertAfter(3,234.33);
    a.display();
    a.InsertBefore(1, 143.33);
    a.display();
    a.InsertBefore(4, 700.33);
    a.display();
    return 0;
}