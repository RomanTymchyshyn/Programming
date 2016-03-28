#include <iostream>

using namespace std;


template<class T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node * next;
	}*p;
public:
	Stack();

	void Push_back(T);
	void Pop_back();
	void Display();
};

template<class T>
Stack<T>::Stack()
{
	p=NULL;
};

template<class T>
void Stack<T>::Push_back(T a)
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
void Stack<T>::Pop_back()
{
   Node *q,*r;
   q = p;
   r = q;
   while( q!=NULL )
   {
        if( q->next==NULL )
      {
           r->next = q->next;
         Delete q;
         return;
      }
 
      r = q;
      q = q->next;
   }


}

template<class T>
void Stack<T>::Display()
{
   Node *q;
   cout<<endl;
 
   for(q=p;q!=NULL;q=q->next)
        cout<<endl<<q->data;
   cout<<endl;
 
}