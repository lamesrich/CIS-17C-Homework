//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<#>/main.cpp
/// @brief Assignment/Lab <#, e.g. 1,2,3..10> for CS 10 <quarter & year>
///
/// @author <Your name> [fake@email.com]
/// @date <Current date>
///
/// @par Enrollment Notes
///     Lecture Section: <e.g. 001>
/// @par
///     Lab Section: <e.g. 021>
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============


#ifndef _Vector_H_
#define _Vector_H_


using namespace std;


template <class T>
class Vector
{
private:
    unsigned sz;
    unsigned cap;
    T *data;
public:
    Vector();//
    Vector( unsigned size);//
    Vector( unsigned size, T value);//
    ~Vector();// destructor
    unsigned size() const;//
    unsigned capacity( ) const;//
    bool empty( ) const;//
    const T & at( unsigned index ) const;
    T & at( unsigned index );
    void insert( unsigned index, T value );
    void erase( unsigned index );
    const T & front( ) const;
    T & front( );
    const T & back( ) const;
    T & back( );
    void assign( unsigned n, int value );
    void print();
    void push_back( T value );
    void pop_back( );
    void clear( );
    void resize( unsigned size );
    void resize( unsigned size, T value );
    void reserve( unsigned n );
    void sort();
private:
    void expand();//
    void expand(unsigned amount);//
    
};

template<class T>
Vector<T> :: Vector()
{
    sz = 0;
    cap = 0;
    data = 0;
}


template<class T>
Vector<T> :: Vector( unsigned size )
{
    sz = size;
    cap = size;
    data = new int[cap];
    for(unsigned i = 0; i < cap; i++)
    {
        data[i] = 0;
    }
}

template<class T>
Vector<T> :: Vector( unsigned size, T value)
{
    sz = size;
    cap = size;
    data = new T[cap];
    for(unsigned i = 0; i < cap; i++)
    {
        data[i] = value;
    }
}

template<class T>
Vector<T> :: ~Vector()
{
    delete [] data;
}

template<class T>
unsigned Vector<T> :: size() const
{
    return sz;
}

template<class T>
unsigned Vector<T> :: capacity() const
{
    return cap;
}

template<class T>
bool Vector<T> :: empty() const
{
    if(sz == 0)
        return true;
    else return false;
}

template<class T>
const T& Vector<T> :: at( unsigned index ) const
{
    if(index >= sz)
    {
        exit(1);// ends with errors
    }
    return data[index];
    
}

template<class T>
T & Vector<T> :: at( unsigned index )
{
    if(index >= sz)
    {
        exit(1);
    }
    return data[index];
    
}

template<class T>
void Vector<T> :: insert( unsigned index, T value )
{
    if(sz >= cap)
    {
        expand();
    }
    
    for(unsigned i = sz; i > index; i--)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
    sz++;
}

template<class T>
void Vector<T> :: erase( unsigned index )
{
    if(index >= sz)
    {
        exit(1);
    }
    for(unsigned i = index; i < sz - 1; i++)
    {
        data[i] = data[i + 1];
    }
    sz--;
}

template<class T>
const T & Vector<T> :: front( ) const
{
    return data[0];
}

template<class T>
T & Vector<T> :: front()
{
    return data[0];
}

template<class T>
const T & Vector<T> :: back() const
{
    return data[sz - 1];
}

template<class T>
T & Vector<T> :: back()
{
    return data[sz - 1];
}

template<class T>
void Vector<T> :: assign( unsigned n, int value )
{
    delete [] data;
    sz = n;
    cap = n;
    data = new int[cap];
    reserve(n);
    for(unsigned i = 0; i < cap; i++)
    {
        data[i] = value;
    }
}
template<class T>
void Vector<T> :: print()
{
    for(unsigned i = 0; i < sz; i++)
    cout << data[i] << " ";
    cout << endl;
}
template<class T>
void Vector<T> :: push_back( T value )
{
    insert(sz, value);
}

template<class T>
void Vector<T> :: pop_back()
{
    if(sz == 0)
    {
        exit(1);
    }
    sz--;
}

template<class T>
void Vector<T> :: clear()
{
    sz = 0;
}

template<class T>
void Vector<T> :: resize( unsigned size )
{
    resize(size, 0);
}

template<class T>
void Vector<T> :: resize( unsigned size, T value )
{
    
    if(size < sz)
    {
        sz = size;
    }
    
    else if(size > sz)
    {
        reserve(size);
        for(unsigned i = sz; i < size; i++)
        {
            data[i] = value;
        }
        sz = size;
    }
}

template<class T>
void Vector<T> :: reserve( unsigned n )
{
    if((n > cap) && (n <= 2 * cap))
    {
        expand();
    }
    else if( n > 2 * cap) expand(n - cap);
    
}
template<class T>
void Vector<T> :: sort()
{
    for(unsigned i = 0; i < sz; i++)
    {
        for(unsigned j = i + 1; j < sz; j++)
        {
            if(data[i] < data[j]) swap(data[i], data[j]);
        }
    }
}




template<class T>
void Vector<T> :: expand()
{
    if(cap == 0)
    {
        cap = 1;
    }
    else cap *= 2;
    T * temporate;
    temporate = new T[cap];
    for(unsigned i = 0; i < sz; i++)
    {
        temporate[i] = data[i];
    }
    delete [] data;
    data = temporate;
}
template<class T>
void Vector<T> :: expand(unsigned amount)
{
    cap += amount;
    T * temporate;
    temporate = new T[cap];
    for(unsigned i = 0; i < sz; i++)
    {
        temporate[i] = data[i];
    }
    delete [] data;
    data = temporate;
}
#endif // Vector_H_