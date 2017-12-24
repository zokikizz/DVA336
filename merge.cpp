#include <iostream>
#include <ctime>

using namespace std;


// print array 
void printArray(int *a, int start, int end)
{
    for(int i = start; i < end; i++)
        cout << a[i] << " ";
    cout << endl;
}

//init
void initArray(int *a, int n)
{
    for(int i = 0; i < n; i++)
        a[i] = (n-1) - i;
    
 //   cout << "Array: ";
//    printArray(a, 0, n);
}

//merge right and left
void merge(int *dst, int s,int m, int e)
{
    //cout << "Start of merging" << endl;
    //printArray(dst, s, e);
    int temp[e-s];
    int il = s, ir = m, it = 0;
    while( il < m && ir < e)
    {
        if(dst[il] < dst[ir])
            temp[it++] = dst[il++];
        else
            temp[it++] = dst[ir++];
    }
    
    while( il < m)
    {
        temp[it++] = dst[il++];
    }
    
    while( ir < e)
    {
        temp[it++] = dst[ir++];
    }
    
    //copying result
    for(int i = 0; i < (e-s); i++)
        dst[s+i] = temp[i];
    
    
    //cout << "After merging" << endl;
   // printArray(dst, s, e);
}

//to devide array 
void devide(int *a, int s, int e)
{
    if( e - s == 1 )
    {
       // printArray(a, s, e);
        return;
    }
    else 
    {
        int m = (s+e)/2;
        devide(a, s, m);
        devide(a, m, e);
        merge(a, s, m, e);

    }
}

int main() 
{
    int *array;
    int n;
    clock_t seqTime;
    
    
    cout << "Input size of array:";
    cin >> n;
    
    array = new int[n];
        
    initArray(array, n);
    
    seqTime = clock();
    devide(array, 0, n);
    cout << "Seqential exectution time: " << ((float)(clock() - seqTime))/CLOCKS_PER_SEC << endl;
    cout << "Clocks: " << CLOCKS_PER_SEC << endl; 
}