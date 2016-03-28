#include <iostream>

using namespace std;


template<class T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node * next;
	}*p;
public:
	
	Queue();

	void Push_back(T);
	void Pop_front();
	void Display();
};

template<class T>
Queue<T>::Queue()
{
	p=NULL;
};

template<class T>
void Queue<T>::Push_back(T a)
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
void Queue<T>::Pop_front()
{
   Node *q;
   q = p;
   p=q->next;


}

template<class T>
void Queue<T>::Display()
{
   Node *q;
   cout<<endl;
 
   for(q=p;q!=NULL;q=q->next)
        cout<<endl<<q->data;
   cout<<endl;
 
}
