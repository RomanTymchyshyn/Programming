#ifndef CLASS_VECTOR
#define CLASS_VECTOR

#include <stdio.h>
#include <cmath>
#include <xstring>

using namespace std;

#define assert(expression) if (!expression)\
						   {cout<<endl<<#expression<<endl;\
							cout<<"line:"<<__LINE__<<endl;\
							cout<<"file:"<<__FILE__<<endl;\
							cin.get();\
							exit(0);}
#define vector_out_of_range (i<_size && i>=0)

template <class T>
class vector
{
		T *arr;
		int _size;
		int capacity;
	public:
		vector ();
		vector (const int & _size_);
		vector (const int & _size_, const T & value);
		vector (const vector & v);
		int size () {return _size;};
		T & operator[] (const int & i);
		void push_back (const T & value);
		void pop_back () {--_size;};
		void insert (const int & Where, const T & value, const int & amount = 1);
		void erase (const int & Where, const int & amount = 1);
		int find(const T & value);
		void BetcherSort();
		void ShellSort();
		void out();
		~vector();
};

template<class T>
vector<T>::vector()
{
	arr = NULL;
	_size = 0; 
	capacity = 0;
}

template<class T>
vector<T>::vector(const int & _size_)
{
	arr=new T[_size_];
	if (arr == NULL)
	{
		capacity = 0;
		_size = 0;
	}
	else
	{
		capacity = _size_;
		_size=0;
	}
}

template<class T>
vector<T>::vector(const int & _size_, const T & value)
{
	arr=new T[_size_];
	if (arr == NULL)
	{
		capacity = 0;
		_size = 0;
	}
	else
	{
		capacity=_size_;
		_size=_size_;
		for (int i = 0; i < _size; ++i)
			arr[i]=value;
	}
}

template<class T>
vector<T>::vector(const vector & v)
{
	capacity = v.capacity;
	_size = v._size;
	arr=new T[capacity];
	for (int i = 0; i < _size; ++i)
		arr[i]=v.arr[i];
}

template<class T>
T & vector<T>::operator[](const int & i)
{
	 if (i<0 || i>=_size)
	 {
		 _Xout_of_range("vector out of range");
		 /*or thisway
		 assert(vector_out_of_range);*/ 
	 }
	 return arr[i];
}

template<class T>
void vector<T>::push_back(const T & value)
{
	if (_size==capacity)
	{
		T * temp = new T[_size];
		if (_size==0) capacity = 2;
		if (_size < 10) capacity = capacity*2;
		if (_size > 10) capacity = capacity + 20;
		for (int i=0; i < _size; ++i)
			temp[i]=arr[i];
		delete arr;
		arr=new T[capacity];
		for (int i=0; i < _size; ++i)
			arr[i]=temp[i];
		delete []temp;
	}
	arr[_size++]=value;
	return;
}

template<class T>
void vector<T>::insert(const int & Where, const T & value, const int & amount = 1)
{
	if (Where<0 || Where>=_size)
		 _Xout_of_range("vector out of range");
	/*or thisway
	assert(Where>=0 && Where<_size);*/
	_size+=amount;
	if (_size > capacity)
	{
		T * temp = new T[_size];
		for (int i=0; i < _size; ++i)
			temp[i]=arr[i];
		delete []arr;

		if (_size<10) capacity=_size*2;
		if (_size>10) capacity=_size+20;

		arr = new T[capacity];

		for (int i=0; i<=Where; ++i)
			arr[i]=temp[i];
		for (int i=Where+1; i<=Where+amount; ++i)
			arr[i]=value;
		for (int i=Where+amount+1; i<_size; ++i)
			arr[i]=temp[i-amount];
		delete []temp;
	}
	else
	{
		for (int i=Where+1; i<=Where+amount; ++i)
		{
			arr[i+amount]=arr[i];
			arr[i]=value;
		}
	}
}

template<class T>
void vector<T>::erase(const int & Where, const int & amount)
{
	for (int i=Where; i<Where+amount; ++i)
		arr[i]=arr[i+amount];
	_size-=amount;
	return;
}

template<class T>
int vector<T>::find(const T & value)
{
	for (int i=0; i<_size; ++i)
		if (arr[i]==value) return i;
	return -1;
}

template<class T>
void vector<T>::BetcherSort()
{
	int N=size();
	int t=ceil(log(double(N))/log(2.0));
	int p=pow(2.0,double(t-1));
	int p1=p;
	int r,q,d;
	while (p>0)
	{
		out();

		q=p1;
		r=0;
		d=p;
		for (int i=0; i<N-d; ++i)
		{
			//if ((i & p) == r && arr[i]>arr[i+d])
				swap(arr[i], arr[i+d]);
		}
		//if (q!=p)
		{
			d=q-p;
			q=q/2;
			r=p;
		}
		p=p/2;
	}
}

template<class T>
void vector<T>::out()
{
	for (int i=0; i<size(); ++i)
		cout<<arr[i]<<' ';
	cout<<endl<<"======="<<endl;
}

template<class T>
void vector<T>::ShellSort()
{
	int N=size();
	int t=ceil(log(double(N))/log(2.0));
	vector<int> h;

	//шукаємо значення зміщень по формулі Седжвіка
	int temp=0;
	int pow_2_1=1;
	int pow_2_2=1;

	for (int s=0; s<t; ++s)
	{
		if (s%2==0)
		{
			temp=9*pow_2_1-9*pow_2_2+1;
			if (3*temp>N) break; else h.push_back(temp);
			pow_2_1*=2;
			pow_2_2*=2;
		}
		if (s%2==1)
		{
			temp=8*pow_2_1-6*pow_2_2+1;
			if (3*temp>N) break; else h.push_back(temp);
			pow_2_1*=2;
		}
	}

	//основний цикл
	int H=0;
	int j=0;
	T K;

	for (int s=h.size()-1; s>=0; --s)
	{
		H=h[s];
		for (int i=H; i<N; ++i)
		{
			K=arr[i];
			j=i;
			while (j-h[s]>=0 && arr[j-h[s]]>K)
			{
				arr[j]=arr[j-h[s]];
				j=j-h[s];
			}
			arr[j]=K;
		}
	}
}

template<class T>
vector<T>::~vector()
{
	if (arr != NULL) delete []arr;
	_size = 0;
	capacity = 0;
}

#endif