//
//  main.cpp
//  Mid_Term
//
//  Author: Zexi Sun on 11/3/15.




#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include "Vector.h"
#include "StatClass6.h"
#include "List.h"
#include "FrequencyList.h"



using namespace std;



Vector<int> *top(Vector<int> &, unsigned p);// Question 1
bool cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs);
vector<pair<int, int> > *countMode(Vector<int> &a, unsigned size);
void fillVector(Vector<int> &a, unsigned size);
float getAve(Vector<int> &temp);

vector<pair<int, int> > *countMode(Vector<int> &a, unsigned size);
bool cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs);


List<int> *top(List<int>, int);

void fillList(List<int> &, int);
FrequencyList mode(List<int> &x);
StatClass6 stat(List<int> &);

void clear();

float t(float x);


float h(float x);
float g(float x);


class StatClass
{
private:
    int min;
    int max;
    float ave;
    vector<pair<int, int> > *mode; // key, frequency
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

int interface();

void main1();
void main2();
void main3();
void main4();
void main5();
void main6();
void main8();
void main9();


int main()
{
    int choice;
    char c;
    while(1)
    {
        choice = interface();
        if(choice == 0) break;
        switch (choice)
        {
            case 1: main1();
                break;
            case 2: main2();
                break;
            case 3: main3();
                break;
            case 4: main4();
                break;
            case 5: main5();
                break;
            case 6: main6();
                break;
            case 8: main8();
                break;
            case 9: main9();
                break;
                
            default: cout << "Invalid Input, input again" << endl;
                break;
        }
        cout << endl << endl;
        cout << "Continue(Y/N)? ";
        cin >> c;
        if(c == 'n' || c == 'N') break;
        cout << endl << endl << endl << endl;
    }
    return 0;
}

void main1()
{
    srand((unsigned)time(0));
    cout << "Question 1" << endl;
    unsigned size = 100;
    Vector<int> a;
    fillVector(a, size);
    cout << "The original Vector" << endl;
    a.print();
    a.sort();
    cout << endl;
    cout << "Sorted Vector" << endl;
    a.print();
    Vector<int> *result = top(a, 10);
    
    cout << endl;
    cout << "The top 10 elements" << endl;
    
    result -> print();
}
void main2()
{
    srand((unsigned)time(0));
    Vector<int> a;
    unsigned size = 1000;
    fillVector(a, size);
    a.print();
    cout << endl;
    
    //print frequency
    cout << endl;
    //cout << "Key and Frequency" << endl;
    
    vector<pair<int, int> > *result = countMode(a, size);
    cout << endl;
    
    
    cout << "The mode is " << endl;
    for(unsigned i = 0; i < result -> size(); i++)
    {
        cout << result -> at(i).first << "  " << result -> at(i).second << endl;
    }
    
    
    
}
void main3()
{
    srand((unsigned)time(0));
    Vector<int> a;
    unsigned size = 100;
    fillVector(a, size);
    // sorted vector
    a.print();
    int ave = getAve(a);
    StatClass result(a, a.at(size - 1), a.at(0), ave);
    result.print();
}

void main4()
{
    srand((unsigned)(time(0)));
    int size = 100;
    List<int> a;
    fillList(a, size);
    a.display();
    cout << endl;
    cout << "The top 10 elements are: ";
    List<int> *result;
    result = top(a, 10);
    result -> display();
}

void main5()
{
    srand((unsigned)(time(0)));
    int size = 100;
    List<int> a;
    fillList(a, size);
    a.display();
    cout << endl;
    FrequencyList result = mode(a);
    cout << endl;
    result.print();

}

void main6()
{
    srand((unsigned)(time(0)));
    int size = 100;
    List<int> a;
    fillList(a, size);
    a.display();
    cout << endl;
    FrequencyList result = mode(a);
    result.print();
    StatClass6 ImportantValue = stat(a);
    ImportantValue.print();
}
void main8()
{
    cout << "tan 1 = " << tan(1) << endl;
    cout << "t(1) = " << t(1) << endl;
}

void main9()
{
    
    float x = 1;
    cout << "h(1) = ";
    cout << h(x) << endl;
    cout << "sinh(1) = " << sinh(1) << endl;
    cout << endl;
}

int interface()
{
    cout << "----------Mid Term By Zexi Sun-----------" << endl;
    cout << "|                                       |" << endl;
    cout << "|       Problem 1                       |" << endl;
    cout << "|       Problem 2                       |" << endl;
    cout << "|       Problem 3                       |" << endl;
    cout << "|       Problem 4                       |" << endl;
    cout << "|       Problem 5                       |" << endl;
    cout << "|       Problem 6                       |" << endl;
    cout << "|       Problem 8                       |" << endl;
    cout << "|       Problem 9                       |" << endl;
    cout << "|                                       |" << endl;
    cout << "----------------------------------------|" << endl;
    cout << "Please input the question number(1, 2, 3, 4, 5, 6, 8, 9) and 0 for quit: ";
    int choice;
    cin >> choice;
    cout << endl;
    return choice;

}
Vector<int> *top(Vector<int> &a, unsigned p)
{
    Vector<int> *temp = new Vector<int>;
    for(unsigned i = 0; i < p; i++)
    {
        temp -> push_back(a.at(i));
    }
    return temp;
    
}
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




// no.2


// find mode; and put each mode number in a new my own Vector.
// Will show the frequency of each value.
// Return that Vector

vector<pair<int, int> > *countMode(Vector<int> &a, unsigned size)
//void countMode(Vector<int> &a, unsigned size)
{
    vector<pair<int, int> > *temp = new vector<pair<int, int> >;
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
    vector<pair<int, int> > mode(key.begin(), key.end());
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

bool cmp_by_value(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
    return lhs.second > rhs.second;
}

// no.3




float getAve(Vector<int> &a)
{
    float total = 0;
    for(unsigned i = 0; i < a.size(); i++)
    {
        total += a.at(i);
    }
    return total / static_cast<float>(a.size());
    
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



// no.4


List<int> *top(List<int> a, int p)
{
    List<int> *result = new List<int>;
    for(int i = 0; i < p; i++)
    {
        result -> append(a.first());
        a.pop_fornt();
    }
    return result;
}

// fill the list
// and sort the list
void fillList(List<int> &a, int size)
{
    for(int i = 0; i < size; i++)
    {
        a.List :: append(rand() % 21);
        
    }
    a.List :: sort();
    
}


//no.5

FrequencyList mode(List<int> &x)
{
    map<int, int> frequency;
    frequency = x. List :: frequency();
    vector<pair<int, int> > key(frequency.begin(), frequency.end());
    sort(key.begin(), key.end(), cmp_by_value);
    cout << "Sorted Frequency" << endl;
    for(unsigned i = 0; i < key.size(); i++)
    {
        cout << key.at(i).first << "  " << key.at(i).second << endl;
    }
    
    FrequencyList mode(key);
    
    
    
    
    return mode;
}

// no.6



StatClass6 stat(List<int> &x)
{
    int max = x.List :: first();
    int min = x.List :: last();
    int total = x.List :: getTotal();
    
    StatClass6 result(max, min, total);
    return result;
}

// no.8


float t(float x)
{
    float epsilon = 1e-2f;
    if(x < epsilon) return x + (x * x * x) / 3;
    else return (2 * t(x / 2)) / (1 - t(x / 2) * t(x / 2));
    
    
}

// no.9


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


void clear()
{
    cout << "Clear called" << endl;
    for(int i = 0 ; i < 50; i++)
        cout << endl;
}