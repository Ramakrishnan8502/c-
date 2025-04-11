#include <iostream>
#include "io.h"
using namespace std;

template <class T>
 class BinarySearch
 {
    private:
    T *A;
    int n;
    public:
    BinarySearch(int);
   int Bsearch(int,int,T);
 };

template <class T>
 BinarySearch<T>::BinarySearch(int n)
 {
    A = new T[n];
    cout<<"Enter a number in ascending order";
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
      cin>>A[i];
    }
 }

template <class T>
int BinarySearch<T>::Bsearch(int low,int high,T key)
{ 
    cout<<"ssucessfull search";
   while(low<= high)
   {
      int mid = (low + high)/2;
      if(key == A[mid])
      {
          cout<<"ssucessfull search";
         return mid+1; //sucessfull
      }
      else if(key < A[mid])
      {
         high = mid-1;
      }
      else
      {
         low = mid+1;
      }
   }
   cout<<"unsucessfull search";
   return -1; //unsucessfull
}

int main()
{
   int n,low,high,key;
   cout << "Enter the number of data element in a array \n";
   cin >> n;
   BinarySearch<int> obj(n);
   cout<<"Enter the key element \n";
   cin>>key;
   low = 0;
   high = n-1;
   int rval =   obj.Bsearch(low,high,key);
   cout<<"The return value index is = "<<rval-1 << " th index";

   return 0;
}