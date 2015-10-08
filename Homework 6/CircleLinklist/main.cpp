#include <iostream>
#include <cstdlib>
#include "Circlelink.h"

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
    cout << "lalalala" << endl;
    cout << a.sz() << endl;
    LnkdLst<float> b(a);
    b.display();
    cout << "ds " << endl;
    return 0;
}