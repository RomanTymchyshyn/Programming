#ifndef CLASS_LIST
#define CLASS_LIST

#include <stdio.h>
#include <cmath>

using namespace std;

#define assert(exp) if (!exp)\
						   {cout<<endl<<"There are less than "<<i+1<<" elements in list"<<endl;\
							cout<<"line:"<<__LINE__<<endl;\
							cout<<"file:"<<__FILE__<<endl;\
							cin.get();\
							exit(0);}

template<class T>
struct list_element
{
	list_element * next;
	list_element * previous;
	T value;
};

template<class T>
class list
{
		list_element<T> * first;
		list_element<T> * last;
	public:
		list(){first=NULL; last=NULL;};
		void push_back(const T & value_);
		void push_front(const T & value_);
		T & operator[](const int & i);
		void insert(const int & Where, const T & value_);
		void erase(const int & Where, const int & amount=1);
		int find(const T & value_);
		bool empty(){if(first==NULL && last==NULL) return 1; else return 0;};
		~list();
};

template<class T>
void list<T>::push_back(const T & value_)
{
	if (last==NULL)
	{
		list_element<T> * temp = new list_element<T>;
		temp->next=temp->previous=NULL;
		temp->value=value_;
		first=last=temp;
	}
	else
	{
		list_element<T> * temp = new list_element<T>;
		temp->previous=last;
		temp->next=NULL;
		temp->value=value_;
		last->next=temp;
		last=temp;
	}
}

template<class T>
void list<T>::push_front(const T & value_)
{
	if (last==NULL)
	{
		list_element<T> * temp = new list_element<T>;
		temp->next=temp->previous=NULL;
		temp->value=value_;
		first=last=temp;
	}
	else
	{
		list_element<T> * temp = new list_element<T>;
		temp->previous=NULL;
		temp->next=first;
		temp->value=value_;
		first->previous=temp;
		first=temp;
	}
}

template<class T>
T& list<T>::operator[](const int & i)
{
	list_element<T> * temp = first;
	for (int j = 0; j<i; ++j)
	{
		assert(temp != NULL);
		temp = temp->next;
	}
	return temp->value;
}

template<class T>
void list<T>::insert(const int & Where, const T & value_)
{
	list_element<T> * temp = first;
	for (int i=0; i<Where; ++i)
	{
		assert(temp!=NULL);
		temp=temp->next;
	}
	if (temp==NULL)
	{
		push_back(value_);
		return;
	}
	else 
		if (temp==first)
		{
			push_front(value_);
			return;
		}
	list_element<T> * elem = new list_element<T>;
	elem->value=value_;
	elem->next=temp;
	elem->previous=temp->previous;
	temp->previous->next=elem;
	temp->previous=elem;
	return;
}

template<class T>
void list<T>::erase(const int & Where, const int & amount)
{
	if (first==NULL) return;
	list_element<T> * temp=first;
	for (int i=0; i<Where-1; ++i)
	{
		assert (temp!=NULL);
		temp=temp->next;
	}
	list_element<T> * del;
	list_element<T> * previous = temp->previous;
	for (int i=0; i<amount; ++i)
	{
		assert (temp!=NULL);
		del=temp;
		temp=temp->next;
		delete del;
	}
	if (temp == NULL)
	{
		last=previous;
		previous->next=NULL;
	}
	else
		if (previous == NULL)
		{
			first=temp;
			temp->previous=NULL;
		}
		else
		{
			previous->next=temp;
			temp->previous=previous;
		}
	return;
}

template<class T>
int list<T>::find(const T & value_)
{
	list_element<T> * temp = first;
	if (temp == NULL) return -1;
	int i=0;
	while (temp->value != value_)
	{
		temp=temp->next;
		if (temp==NULL) return -1;
		++i;
	}
	return i;
}

template<class T>
list<T>::~list()
{
	list_element<T> * temp = first;
	while (first != NULL)
	{
		first=temp->next;
		delete temp;
		temp=first;
	}
	last=NULL;
	delete temp;
}

#endif