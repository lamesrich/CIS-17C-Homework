//triangualrmatrix.cpp using template class
//Author: Zexi Sun 2521171
//Date:9/8/2015
//Email: zsun3@student.rcc.edu

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template<class T>
class Triangualrmatrix
{
    private:
        int *d1ary;
        T **d2ary;
        int rows;
        int cols;
    public:
        Triangualrmatrix(int, int);
        int *filAray(int);
        void filAray(int *, int);
        void prntAry();
        ~Triangualrmatrix();
            
};
template<class T>
Triangualrmatrix<T> :: Triangualrmatrix(int numrows, int numcols)
{
    rows = numrows;
    cols = numcols;
    d1ary = filAray(rows);
    filAray(d1ary, rows);
}

template<class T>
int *Triangualrmatrix<T> :: filAray(int n)
{
    int *array = new int[n];
    for(int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }
    d1ary = array;
    return array;
}

template<class T>
void Triangualrmatrix<T> :: filAray(int *cols, int nCols)
{
    T **array = new T *[nCols];
    for(int i = 0; i < nCols; i++)
    {
        array[i] = new T[cols[i]];
    }
    
    for(int row = 0; row < nCols; row++)
    {
        for(int col = 0; col < cols[row]; col++)
        {
            array[row][col] = static_cast<T>(rand()%100 + 1);
        }
    }
    d2ary = array;
}

// template<class T>
// void Triangualrmatrix<T> :: prntAry( int n)
// {
//     cout << endl;
//     for(int i = 0; i < n; i++)
//     {
//         cout << d[i] << " ";
//     }
//     cout << endl;
// }

template<class T>
void Triangualrmatrix<T> :: prntAry()
{
    cout << endl;
    for(int row = 0; row < cols; row++)
    {
        for(int col = 0; col < d1ary[row]; col++)
        {
            cout << d2ary[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<class T>
Triangualrmatrix<T> :: ~Triangualrmatrix<T>()
{
  delete []d1ary;
  for(int i = 0; i < cols; i++)
  {
      delete []d2ary[i];
  }
  delete []d2ary;
}