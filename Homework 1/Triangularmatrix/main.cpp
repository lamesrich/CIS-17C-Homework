// Assignment due on 9/9/2015
// Test for integers and floats
// fill randomly with fixed column size in a user defined array. Use template class
// Author: Zexi Sun
// Email zsun3@student.rcc.edu


#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Triangularmatrix.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    
   // Triangualrmatrix<int> d1(10, 10); // integer array
    Triangualrmatrix<float> d2(10, 10); // float array
    float d = 10.1;
    cout << d;
   // d1.prntAry();
    d2.prntAry();
    return 0;
}