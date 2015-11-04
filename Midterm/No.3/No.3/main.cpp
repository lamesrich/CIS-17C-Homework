//
//  main.cpp
//  No.3
//
//  Created by Zexi Sun on 10/31/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

//  25ptrs


//  3)  Vector - Fill a vector with random inputs.  Write a function
//               statClass *stat(vector x) that returns a class that
//               contains the min,max and average of the x vector but
//               also uses a map to solve the mode problem and returns
//               the important elements for the mode.


#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <ctime>
#include "Vector.h"



using namespace std;


bool cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs);
vector<pair<int, int>> *countMode(Vector<int> &a, unsigned size);
void fillVector(Vector<int> &a, unsigned size);
float getAve(Vector<int> &temp);

vector<pair<int, int>> *countMode(Vector<int> &a, unsigned size);
bool cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs);

class StatClass
{
    private:
        int min;
        int max;
        float ave;
        vector<pair<int, int>> *mode; // key, frequency
public:
    StatClass(Vector<int> temp, int big, int small, int ave)
{
    mode = countMode(temp, 100);
    this -> min = small;
    this -> max = big;
    this -> ave = ave;
}
    //    int getMin(Vector<int> &);
    //    int getMax(Vector<int> &);
    //    float getAve(Vector<int> &);
        void print();
    
    
    
    
};


int main()
{
    srand((unsigned)time(0));
    Vector<int> a;
    unsigned size = 100;
    fillVector(a, size);
    // sorted vector
    a.print();
    int ave = getAve(a);
    StatClass result(a, a.at(0), a.at(size - 1), ave);
    result.print();
    return 0;
}
float getAve(Vector<int> &a)
{
    float total = 0;
    for(unsigned i = 0; i < a.size(); i++)
    {
        total += a.at(i);
    }
    return total / static_cast<float>(a.size());
    
}
// Vector will be filled and sorted
// in this function.

void fillVector(Vector<int> &a, unsigned size)
{
    vector<int> temp;
    for(unsigned i = 0; i < size; i++)
    {
        temp.push_back((rand() % 51));
    }
    sort(temp.begin(), temp.end());
    for (unsigned i = 0; i < size; i++)
    {
        a.push_back(temp.at(i));
    }
}

void StatClass :: print()
{
    cout << "Result:" << endl;
    cout << "The Max is " << this -> max << endl;
    cout << "The Min is " << this -> min << endl;
    cout << "The Ave is " << this -> ave << endl;
    cout << "The Mode is: " << endl;
    cout << "Key Frequency" << endl;
    for(unsigned i = 0; i < mode -> size(); i++)
    {
        cout << mode -> at(i).first << "   " << mode -> at(i).second << endl;
    }
}
bool cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
    return lhs.second > rhs.second;
}
vector<pair<int, int>> *countMode(Vector<int> &a, unsigned size)
//void countMode(Vector<int> &a, unsigned size)
{
    vector<pair<int, int>> *temp = new vector<pair<int, int>>;
    map<int, int> key;
    map<int, int> :: iterator key_lter;
    
    
    
    int curr = 0;
    int count;
    for(unsigned i = 0; i < size; i++)
    {
        curr = a.at(i);
        count = 1;
        while(i < size - 1 && curr == a.at(i + 1))
        {
            i++;
            count++;
        }
        key.insert(pair<int, int> (curr, count));
        
        
    }
    if(a.at(size - 2) != a.at(size - 1)) key.insert(pair<int, int>(a.at(size - 1), 1));
    
    
    
    //cout << "Hello World" << endl;
    // print the frequency
    cout << "Key Frequency(Unsorted)" << endl;
    for(key_lter = key.begin(); key_lter != key.end(); key_lter++)
    {
        cout << key_lter -> first << " " << key_lter -> second << endl;
    }
    cout << endl << endl;
    
    cout << "Key Frequency(Sorted)" << endl;
    vector<pair<int, int>> mode(key.begin(), key.end());
    sort(mode.begin(), mode.end(), cmp_by_value);
    for(unsigned i = 0; i < mode.size(); i++)
    {
        cout << mode.at(i).first << " " << mode.at(i).second << endl;
    }
    
    cout << endl << endl;
    temp -> push_back(mode.at(0));
    unsigned i = 1;
    while(mode.at(i).second == mode.at(i - 1).second)
    {
        temp -> push_back(mode.at(i));
        if(i == size - 1) break;
        else i++;
        
    }
    return temp;
    
}
