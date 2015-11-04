//
//  StatClass.h
//  No.6
//
//  Created by Zexi Sun on 11/2/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#ifndef StatClass_h
#define StatClass_h
class StatClass
{
private:
    int min;
    int max;
    float ave;
public:
    StatClass();
    StatClass(int, int, float);
    void print();
};

StatClass :: StatClass()
{
    min = 0;
    max = 0;
    ave = 0;
}


StatClass :: StatClass(int min, int max, float ave)
{
    this -> min = min;
    this -> max = max;
    this -> ave = ave;
}

void StatClass :: print()
{
    cout << "The min is " << min << endl;
    cout << "The max is " << max << endl;
    cout << "The ave is " << ave << endl;
    cout << endl;
}



#endif /* StatClass_h */
