//
//  StatClass.h
//  No.6
//
//  Created by Zexi Sun on 11/2/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#ifndef StatClass6_h
#define StatClass6_h
class StatClass6
{
private:
    int min;
    int max;
    float ave;
public:
    StatClass6();
    StatClass6(Vector<int> temp, int big, int small, int ave);
    StatClass6(int, int, float);
    void print();
};

StatClass6 :: StatClass6()
{
    min = 0;
    max = 0;
    ave = 0;
}


StatClass6 :: StatClass6(int min, int max, float ave)
{
    this -> min = max;
    this -> max = min;
    this -> ave = ave;
}

void StatClass6 :: print()
{
    cout << "The min is " << min << endl;
    cout << "The max is " << max << endl;
    cout << "The ave is " << ave << endl;
    cout << endl;
}



#endif /* StatClass_h */
