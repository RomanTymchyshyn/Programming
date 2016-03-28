#include <iostream>
#include <algorithm>
#include <exception>
#include <string>
#include <cstdlib>
#include <ctime>
#define NMAX 50001

template<class T>
void quickSortR(T* a, long N) {


  long i = 0, j = N; 		
  T temp, p;

  p = a[ N>>1 ];		


  do {
    while ( a[i] < p ) i++;
    while ( a[j] > p ) j--;

    if (i <= j) {
      temp = a[i]; a[i] = a[j]; a[j] = temp;
      i++; j--;
    }
  } while ( i<=j );


  
  if ( j > 0 ) quickSortR(a, j);
  if ( N > i ) quickSortR(a+i, N-i);
}
 
void shell_sort (int *a, int n) {
    int h, i, j, k;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            k = a[i];
            for (j = i; j >= h && k < a[j - h]; j -= h) {
                a[j] = a[j - h];
            }
            a[j] = k;
        }
    }
}

void SelectionSort(int A[], int length)
{
    int i, j, min, minat;
	for(i = 0; i<(length-1); i++)
	{
		minat = i;
		min = A[i];

      for(j = i+1;j < length; j++) 
	  {
		  if(min > A[j])   
		  {
			  minat = j;  
			  min = A[j];
		  }
	  }
	  int temp = A[i];
	  A[i] = A[minat];  
	  A[minat]=temp;	
	}
}
int arr[NMAX+1];

void heapify (int pos, int n) {
    while (2 * pos + 1 < n) {
        
        int t = 2 * pos +1;
        if (2 * pos + 2 < n && arr[2 * pos + 2] >= arr[t])
        {
            t = 2 * pos + 2;
        }
        if (arr[pos] < arr[t]) {
            swap(arr[pos], arr[t]);
            pos = t;
        } 
        else break;
        
    }
}

void heap_make(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        heapify(i, n);
    }
}
void heap_sort(int n)
{
    heap_make(n);
    while(n>0)
    {
        swap(arr[0],arr[n-1]);
        n--;
        heapify(0,n);
    }
}

template<class T>
void MergeSort(vector<T> &A)
{
	vector<T> L, R;
	if(A.size()>1)
	{
		for(int i=0; i<A.size()/2; i++)
			L.push_back(A[i]);
		for(int i=A.size()/2; i<A.size(); i++)
			R.push_back(A[i]);
		if(L.size()>1)
			MergeSort(L);
		if(R.size()>1)
			MergeSort(R);
	}
	A.clear();
	int i=0, j=0;
	while(i<L.size() && j<R.size())
	{
		while(j<R.size() && i<L.size() && R[j]<L[i]) 
		{
			A.push_back(R[j]);
			j++;
		}
		while(j<R.size() && i<L.size() && R[j]>=L[i])
		{
			A.push_back(L[i]);
			i++;
		}
	}
	while(j<R.size()) 
		{
			A.push_back(R[j]);
			j++;
		}
	while(i<L.size())
		{
			A.push_back(L[i]);
			i++;
		}
	return;
}