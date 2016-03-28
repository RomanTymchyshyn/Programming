#include <iostream>

using namespace std;


template<class T>
class Deq
{
private:
	struct Node
	{
		T data;
		Node * next;
	}*p;
public:
	
	Deq();

	void Push_back(T);
	void Pop_front();
	void Pop_back();
	void Push_front(T);
	void Display();
};

template<class T>
Deq<T>::Deq()
{
	p=NULL;
};

template<class T>
void Deq<T>::Push_back(T a)
{
	Node *q,*t;

	if(p==NULL)
	{
		p = new Node;
		p->data=a;
		p->next=NULL;
	}
	else
	{
		q=p;
		while(q->next!=NULL)
			q=q->next;
		t= new Node;

		t->data=a;
		t->next=NULL;
		q->next=t;
	}
};

 
template<class T>
void Deq<T>::Pop_front()
{
   Node *q;
   q = p;
   p=q->next;


}

template<class T>
void Deq<T>::Display()
{
   Node *q;
   cout<<endl;
 
   for(q=p;q!=NULL;q=q->next)
        cout<<endl<<q->data;
   cout<<endl;
 
}

template<class T>
void Deq<T>::Pop_back()
{
   Node *q,*r;
   q = p;
   r = q;
   while( q!=NULL )
   {
        if( q->next==NULL )
      {
           r->next = q->next;
         delete q;
         return;
      }
 
      r = q;
      q = q->next;
   }


}

template<class T>
void Deq<T>::Push_front(T num)
{
   Node *q;
 
   q = new Node;
   q->data = num;
   q->next = p;
   p = q;
}