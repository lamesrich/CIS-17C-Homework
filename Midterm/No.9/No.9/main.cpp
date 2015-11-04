//
//  main.cpp
//  No.9
//
//  Author: Zexi Sun on 11/3/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

//  Recursion - Use mutual recursion to implement the following
//              functions
//
//              h(2x)=2h(x)g(x)
//              g(2x)=1+2(h(x)^2)
//
//h(x) ~ x + x^3/6 just test if |x| < epsilon
//g(x) ~ 1 + x^2/2 just test if |x| < epsilon
//
//Epsilon -> accuracy to 6 decimal places is good enough.
//
#include <iostream>
#include <cmath>
#include <cstdlib>

float h(float x);
float g(float x);

using namespace std;

int main(int argc, const char * argv[]) {
    
    float x = 1;
    cout << "h(1) = ";
    cout << h(x);
    cout << endl;
    
    return 0;
}


float h(float x)
{
    float epsilon = 1e-6f;
    if(abs(x) < epsilon) return x + x * x * x / 6;
    else return 2 * h(x / 2) * g(x / 2);
}

float g(float x)
{
    float epsilon = 1e-6f;
    if(abs(x) < epsilon) return 1 + x * x / 2;
    else return 1 + 2 * h(x / 2) * h(x / 2);
}