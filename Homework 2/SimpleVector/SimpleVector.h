#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;



template<class T>
class SimpleVector
{
    private:
        T *aptr; // the vector
        unsigned int cap;// capacity of the vector
        unsigned int sz; // size of the vector
    
    public:
    /*
        Constructors
    */
    SimpleVector();
    SimpleVector(unsigned size);
    SimpleVector(unsigned size, T value);
    
    ~SimpleVector(); // destructor
    
    /* 
        Get the private cap and sz of the vector
    */
    unsigned size() const;
    unsigned capcity() const;
    void push_back(T);
    void pop_back();
    void print() const;
    
    private:
    void expand();
    
        
    
};

template<class T>
SimpleVector<T> :: SimpleVector()
{
    cap = 0;
    sz = 0;
    aptr = 0;
}
/*
*******************************
If the value is not provided, sign 0 to each element in the vector

*******************************
*/
template<class T>
SimpleVector<T> :: SimpleVector(unsigned size)
{
    sz = size;
    cap = size;
    aptr = new T[cap];
    for(unsigned i = 0; i < cap; i++)
    {
        aptr[i] = 0;
    }
}

template<class T>
SimpleVector<T> :: SimpleVector(unsigned size, T value)
{
    sz = size;
    cap = size;
    aptr = new T[cap];
    for(unsigned i = 0; i < cap; i++)
    {
        aptr[i] = value;
    }
}

template<class T>
unsigned SimpleVector<T> :: size() const
{
    return sz;
}

template<class T>
unsigned SimpleVector<T> :: capcity() const
{
    return cap;
}

template<class T>
SimpleVector<T> :: ~SimpleVector()
{
    delete [] aptr;
}

template<class T>
void SimpleVector<T> :: expand()
{
        cap *= 2;
        T *a = new T[cap];
        for(unsigned i = 0; i < sz; i++)
        {
            a[i] = aptr[i];
        }
        delete [] aptr;
        aptr = a;
}

template<class T>
void SimpleVector<T> :: print() const
{
    for(unsigned i = 0; i < sz; i++)
    {
        cout << aptr[i] << " ";
    }
    cout << endl;
}

template<class T>
void SimpleVector<T> :: push_back(T a)
{
    cout << "Push_back:" << endl;
    sz = sz + 1;
    if(sz >= cap) expand();
    aptr[sz - 1] = a;
}

template<class T>
void SimpleVector<T> :: pop_back()
{
    cout << "pop_back:" << endl;
    if(sz == 0) exit(0);
    sz--;
}