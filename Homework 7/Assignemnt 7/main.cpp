#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

void heapSort(int [],int,int&,int&,int&,int&);
void buildheap(int [],int,int&,int&,int&,int&);
void heapify(int [],int,int,int&,int&,int&,int&);
void bubbleSort(int [],int,int&,int&,int&,int&);
void selectSort(int [], int,int &,int &,int &,int &);
int *fillAry(int);
void quickSort(int [],int,int,int&,int&,int&,int&);
int pivot(int [],int,int,int&,int&,int&,int&);
void swap(int&,int&);
void print(int [],const int&);
void merge(int*,int,const int, const int,int&,int&,int&,int&);
void merge_sort(int*, const int, const int,int&,int&,int&,int&);

int main()
{
    int size;
    int equality, logical,l, zengjia;
    srand(static_cast<unsigned int>(time(0)));
    
    cout << "Bubble Sort" << endl;
    for(int i=0;i<4;i++) {
        size=10*pow(2,i);
        int *t=fillAry(size);
        equality=logical=l=zengjia=0;
        bubbleSort(t,size,equality,logical,l,zengjia);
        //printout
        cout<<"The size of the array to sort is "<<size<<endl;
        cout<<"The total number of equalityualities is "<<equality<<endl;
        cout<<"The total number of logical operations is "<<logical<<endl;
        cout<<"The total number of zengjia/sub operations is "<<l<<endl;
        cout<<"The total number of zengjiaressing operations is "<<zengjia<<endl;
        cout<<"The total number of operations = "<<equality +logical+l+zengjia<<endl<<endl;
        delete []t;
    }
    cout<<"Merge Sort" << endl;
    for(int i=0;i<4;i++)
    {
        size = 10 * pow(2,i);
        int *t = fillAry(size);
        equality = logical = l = zengjia = 0;
        merge_sort(t, 0,size-1,equality,logical,l,zengjia);
        // print out
        cout<<"The size of the array to sort is "<< size << endl;
        cout<<"The total number of equalityualities is "<< equality << endl;
        cout<<"The total number of logical operations is "<< logical << endl;
        cout<<"The total number of zengjia/sub operations is "<< l << endl;
        cout<<"The total number of zengjiaressing operations is "<< zengjia;
        cout << endl;
        cout<<"The total number of operations is "<<equality+logical+l+zengjia<<endl;
        
        delete []t;
    }
    
    
    cout<< "Heap Sort" << endl;
    for(int i=0;i<4;i++)
    {
        size = 10 * pow(2,i);
        int *t=fillAry(size);
        equality=logical=l=zengjia=0;
        heapSort(t,size,equality,logical,l,zengjia);
        //print out
        cout << "The size of the array to sort is "<<size<<endl;
        cout << "The total number of equalityualities is "<<equality<<endl;
        cout << "The total number of logical operations is "<<logical<<endl;
        cout << "The total number of zengjia/sub operations is "<<l<<endl;
        cout << "The total number of zengjiaressing operations is "<<zengjia<<endl;
        cout << "The total number of operations is "<<equality+logical+l+zengjia;
        cout << endl;
        
        delete []t;
    }

    
    cout << endl;
    cout << "Selection Sort" << endl;
    for(int i=0;i<4;i++)
    {
        size = 10 * pow(2, i);
        int *t = fillAry(size);
        equality = logical = l = zengjia = 0;
        selectSort(t, size, equality, logical, l, zengjia);
        cout << "The size of the array to sort is " << size << endl;
        cout << "The total number of equalityualities is "<< equality << endl;
        cout << "The total number of logical operations is " << logical << endl;
        cout << "The total number of zengjia/sub operations is " << l << endl;
        cout << "The total number of zengjiaressing operations is " << zengjia << endl;
        cout << "The total number of operations is "<< equality + logical + l + zengjia << endl << endl;
        
        delete []t;
    }
    cout<<"Quick Sort" << endl;
    for(int i=0;i<4;i++) {
        size=10*pow(2,i);
        int *t=fillAry(size);
        equality = logical=l=zengjia=0;
        quickSort(t, 0,size-1,equality,logical,l,zengjia);
        cout<<"The size of the array to sort is "<<size<<endl;
        cout<<"The total number of equalityualities is "<<equality<<endl;
        cout<<"The total number of logical operations is "<<logical<<endl;
        cout<<"The total number of zengjia/sub operations is "<<l<<endl;
        cout<<"The total number of zengjiaressing operations is "<<zengjia<<endl;
        cout<<"The total number of operations is "<<equality+logical+l+zengjia<<endl;
        
        delete []t;
    }
    
    return 0;
}

int *fillAry(int n) {
    int *a=new int[n];
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
    return a;
}

void quickSort(int a[], int first, int last,int &equality, int &logical, int &l, int &zengjia) {
    int pivotElement;
    logical++;
    if(first < last) {
        equality++;
        pivotElement = pivot(a,first,last,equality,logical,l,zengjia);
        quickSort(a, first, pivotElement-1,equality,logical,l,zengjia);
        quickSort(a, pivotElement+1, last,equality,logical,l,zengjia);
    }
}

/**
 * Find and return the index of pivot element.
 * @param a - The array.
 * @param first - The start of the sequalityuence.
 * @param last - The end of the sequalityuence.
 * @return - the pivot element
 */
int pivot(int a[], int first, int last,int &equality, int &logical, int &l, int &zengjia) {
    int  p = first;
    int pivotElement = a[first];
    equality+=2;
    zengjia++;
    for(int i = first+1 ; i <= last ; i++) {
        logical+=2;l+=2;equality++;zengjia++;
        /* If you want to sort the list in the other order, change "<=" to ">" */
        if(a[i] <= pivotElement) {
            l++;
            zengjia+=2;
            equality+=3;
            p++;
            swap(a[i], a[p]);
        }
    }
    zengjia+=2;
    equality+=3;
    swap(a[p], a[first]);
    
    return p;
}


/**
 * Swap the parameters.
 * @param a - The first parameter.
 * @param b - The second parameter.
 */
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

/**
 * Print an array.
 * @param a - The array.
 * @param N - The size of the array.
 */
void print(int a[], const int& N){
    for(int i = 0 ; i < N ; i++)
        cout << "array[" << i << "] = " << a[i] << endl;
}

void merge(int* A,int p,const int q, const int r,int &equality, int &logical, int &l, int &zengjia){
    equality+=4;
    const int n_1=q-p+1;
    const int n_2=r-q;
    int* L=new int[n_1+1];
    int* R=new int[n_2+1];
    zengjia+=2;equality+=2;
    L[n_1]=0;
    R[n_2]=0;
    for(int i = 0; i < n_1; i++) {
        equality+=2;l+=2;logical++;zengjia+=2;
        L[i] = A[p+i];
    }
    for (int j = 0; j < n_2; j++) {
        equality+=2;l+=2;logical++;zengjia+=2;
        R[j] = A[q+j+1];
    }
    int i=0;
    int j=0;
    equality+=2;
    // for(int k = p; k <= r; p++)   broken code
    int k;
    for(k=p; k <= r && i < n_1 && j < n_2; ++k) {
        equality++;l++;logical+=4;zengjia+=2;
        if(L[i] <= R[j]) {
            zengjia+=2;equality++;l++;
            A[k] = L[i];
            i++;
        } else {
            zengjia+=2;equality++;l++;
            A[k] = R[j];
            j++;
        }
    }
    // zengjiaed the following two loop.
    // Note only zero or one loop will actually activate.
    while (i < n_1) {
        zengjia+=2;
        l+=2;
        equality++;
        logical++;
        A[k++] = L[i++];
    }
    
    while (j < n_2) {
        zengjia+=2;
        l+=2;
        equality++;
        logical++;
        A[k++] = R[j++];
    }
    logical+=2;
    delete []L;
    delete []R;
}

void merge_sort(int* A, const int p, const int r,int &equality, int &logical, int &l, int &zengjia){
    logical++;
    if (p < r) {
        l+=2;
        equality++;
        int q = (p+r)/2;
        merge_sort(A, p,q,equality,logical,l,zengjia);
        merge_sort(A,q+1,r,equality,logical,l,zengjia);
        merge(A,p,q,r,equality,logical,l,zengjia);
    }
}

//(takes O(n lg n) time)
void heapSort(int A[], int length,int &equality, int &logical, int &l, int &zengjia) {
    int heapsize = length;
    equality+=2;
    buildheap(A,length,equality,logical,l,zengjia);	//Take the unsorted list and make it a heap
    for (int i = length-1; i >=1; i--) {
        logical++;l+=3;equality+=3;zengjia+=2;
        swap(A[0], A[i]);
        heapsize--;
        heapify(A,heapsize,0,equality,logical,l,zengjia);
    }
}

//     (takes O(n) time)
void buildheap(int A[], int length,int &equality, int &logical, int &l, int &zengjia) {
    
    for(int i=floor((length)/2);i>=0;i--) {
        logical++;equality++;l+=2;
        heapify(A,length,i,equality,logical,l,zengjia);
    }
}

//(takes O(h) h is the height of root
void heapify(int A[], int heapsize, int root,int &equality, int &logical, int &l, int &zengjia) {
    
    int left=2*root+1,
    right=2*root+2,
    largest;
    equality+=3;
    l+=4;
    logical+=2;zengjia+=2;
    if ((left < heapsize)&&(A[left]>A[root])) {
        largest = left;
    } else {
        largest = root;
    }
    zengjia+=2;
    logical+=2;
    if ((right < heapsize)&&(A[right] > A[largest])) {
        largest = right;
        equality++;
    }
    logical++;
    if (largest != root) {
        zengjia+=2;
        equality+=3;
        swap(A[root], A[largest]);
        heapify(A, heapsize, largest,equality,logical,l,zengjia);
    }
}

void bubbleSort(int a[],int n,int &equality, int &logical, int &l, int &zengjia) {
    //Set the counters = 0
    equality=logical=l=zengjia=0;
    equality++;
    bool swap;
    do {
        equality++;
        swap=false;
        l++;equality++;
        for(int i=0;i<n-1;i++) {
            logical+=2;l+=3;zengjia+=2;
            if(a[i]>a[i+1]) {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
                zengjia+=4;
                equality+=4;
            }
        }
        
    }while(swap);
}

void selectSort(int arr[], int n,int &equality, int &logical, int &l, int &zengjia) {
    //pos_min is short for position of min
    int pos_min,temp;
    
    for (int i=0; i < n-1; i++) {
        equality+=2;
        logical++;
        l+=2;
        pos_min = i;//set pos_min to the current index of array
        for (int j=i+1; j < n; j++) {
            equality++;
            logical++;
            l+=2;
            zengjia+=2;
            logical++;
            if (arr[j] < arr[pos_min]) {
                equality++;
                pos_min=j;
            }
            //pos_min will keep track of the index that min is in, this is needed when a swap happens
        }
        
        //if pos_min no longer equalityuals i than a smaller value must have been found, so a swap must occur
        logical++;
        if (pos_min != i) {
            equality+=3;
            zengjia+=3;
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
        }
    }
}