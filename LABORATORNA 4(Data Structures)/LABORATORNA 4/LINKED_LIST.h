#include <iostream>

using namespace std;


template<class T>
class List
{
private:
	struct Node
	{
		T data;
		Node * next;
	}*p;
public:
	
	List();

	void Push_back(T);
	void Insert(int,T);
	void Del(T);
	void Display();
};

template<class T>
List<T>::List()
{
	p=NULL;
};

template<class T>
void List<T>::Push_back(T a)
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
void List<T>::Insert(int c,T a)
{

   Node *q,*t;
   int i;
   for(i=0,q=p;i<c;i++)
   {
        q = q->next;
      if( q == NULL )
      {
         return;
      }
   }
 
   t = new Node;
   t->data = a;
   t->next = q->next;
   q->next = t;
}
 
template<class T>
void List<T>::Del(T a)
{
   Node *q,*r;
   q = p;
   if( q->data == a )
   {
        p = q->next;
      delete q;
      return;
   }
 
   r = q;
   while( q!=NULL )
   {
        if( q->data == a )
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
void List<T>::Display()
{
   Node *q;
   cout<<endl;
 
   for(q=p;q!=NULL;q=q->next)
        cout<<endl<<q->data;
   cout<<endl;
 
}


