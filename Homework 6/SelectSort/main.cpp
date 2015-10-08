#include <iostream>
#include <cstdlib>
#include "LnkdLst.h"

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
    a.find(111);
    a.display();
    a.find(1000);
    a.display();
    a.select_sort();
    a.display();
    return 0;
}