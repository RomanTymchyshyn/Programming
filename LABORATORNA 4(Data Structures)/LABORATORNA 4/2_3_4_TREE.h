#ifndef CLASS_2_3_4_TREE
#define CLASS_2_3_4_TREE

#include <stdio.h>
#include <iostream>

using namespace std;

template<class T>
struct Node
{
	T *val1, *val2, *val3;
	int key1, key2, key3;
	Node * child1;
	Node * child2;
	Node * child3;
	Node * child4;
	Node * parent;
	Node();
	void operator=(Node<T> & a);
	void direct_ord_out(ostream & s=cout);
	void inverse_ord_out(ostream & s=cout);
	void symm_ord_out(ostream & s=cout);
	void del();
	void swap(const int & key);
	void split();
	~Node(){del();};
};

template<class T>
Node<T>::Node()
{
	val1=val2=val3=NULL;
	parent=child1=child2=child3=child4=NULL;
	key1=key2=key3=0;
}

template<class T>
void Node<T>::operator=(Node<T> & a)
{
	if (a.val1!=NULL) this->val1=new T(*a.val1); else this->val1=NULL;
	if (a.val2!=NULL) this->val2=new T(*a.val2); else this->val2=NULL;
	if (a.val3!=NULL) this->val3=new T(*a.val3); else this->val3=NULL;
	this->key1=a.key1;
	this->key2=a.key2;
	this->key3=a.key3;
	if (a.child1!=NULL)
	{
		this->child1=new Node<T>(*a.child1);
		this->child1->parent=this;
	}
	else this->child1=NULL;
	if (a.child2!=NULL)
	{
		this->child2=new Node<T>(*a.child2);
		this->child2->parent=this;
	}
	else this->child2=NULL;
	if (a.child3!=NULL)
	{
		this->child3=new Node<T>(*a.child3);
		this->child3->parent=this;
	}
	else this->child3=NULL;
	if (a.child4!=NULL) 
	{
		this->child4=new Node<T>(*a.child4);
		this->child4->parent;
	}
	else this->child4=NULL;
	if (a.parent!=NULL)
	{
		this->parent=new Node<T>(*a.parent);
		if ((a.parent)->child1==&a) this->parent->child1=this;
		if ((a.parent)->child2==&a) this->parent->child2=this;
		if ((a.parent)->child3==&a) this->parent->child3=this;
		if ((a.parent)->child4==&a) this->parent->child4=this;
	}
	else this->parent=NULL;
	return;
}

template<class T>
void Node<T>::direct_ord_out(ostream & s)
{
	if (val1!=NULL)
		s<<(*val1)<<endl;
	if (child1!=NULL)
		child1->direct_ord_out(s);
	if (child2!=NULL)
		child2->direct_ord_out(s);
	if (val2!=NULL)
		s<<(*val2)<<endl;
	if (child3!=NULL)
		child3->direct_ord_out(s);
	if (val3!=NULL)
		s<<(*val3)<<endl;
	if (child4!=NULL)
		child4->direct_ord_out(s);
}

template<class T>
void Node<T>::inverse_ord_out(ostream & s)
{
	if (child1!=NULL)
		child1->inverse_ord_out(s);
	if (child2!=NULL)
		child2->inverse_ord_out(s);
	if (val1!=NULL)
		s<<(*val1)<<endl;
	if (child3!=NULL)
		child3->inverse_ord_out(s);
	if (val2!=NULL)
		s<<(*val2)<<endl;
	if (child4!=NULL)
		child4->inverse_ord_out(s);
	if(val3!=NULL)
		s<<(*val3)<<endl;
}

template<class T>
void Node<T>::symm_ord_out(ostream & s)
{
	if (child1!=NULL)
		child1->symm_ord_out(s);
	if (val1!=NULL)
		s<<(*val1)<<endl;
	if (child2!=NULL)
		child2->symm_ord_out(s);
	if (val2!=NULL)
		s<<(*val2)<<endl;
	if (child3!=NULL)
		child3->symm_ord_out(s);
	if (val3!=NULL)
		s<<(*val3)<<endl;
	if (child4!=NULL)
		child4->symm_ord_out(s);
}

template<class T>
void Node<T>::del()
{
	if (child1!=NULL) delete child1;
	if (child2!=NULL) delete child2;
	if (child3!=NULL) delete child3;
	if (child4!=NULL) delete child4;
	if (parent != NULL)
	{
		if (parent->child1 != NULL && parent->child1->val1==val1)
			parent->child1 = NULL;
		else
			if (parent->child2 != NULL && parent->child2->val1==val1)
				parent->child2 = NULL;
			else
				if (parent->child3 != NULL && parent->child3->val1==val1)
					parent->child3 = NULL;
				else 
					if (parent->child4 != NULL && parent->child4->val1==val1)
						parent->child4 = NULL;
	}
	parent=child1=child2=child3=child4=NULL;
	val1=val2=val3=NULL;
	return;
};

template<class T>
void Node<T>::split()
{
	Node<T> * temp=new Node<T>;
	(*temp)=(*this);
	if (parent == NULL)//root is four-child
	{
		//середній стає коренем
			this->parent=NULL;
			this->val1=new T(*temp->val2);
			this->key1=temp->key2;
			this->val2=NULL;
			this->val3=NULL;
			this->key2=0;
			this->key3=0;
		//лівий - першою дитиною
			this->child1 = new Node<T>;
			this->child1->val1=new T(*temp->val1);
			this->child1->key1=temp->key1;
			this->child1->val2=NULL;
			this->child1->val3=NULL;
			this->child1->key2=0;
			this->child1->key3=0;
			if (temp->child1!=NULL)
			{
				this->child1->child1=new Node<T>(*temp->child1);
				this->child1->child1->parent=this->child1;
				this->child1->child2=new Node<T>(*temp->child2);
				this->child1->child2->parent=this->child1;
				this->child1->child3=NULL;
				this->child1->child4=NULL;
			}
		//правий - другою дитиною
			this->child2 = new Node<T>;
			this->child2->parent=new Node<T>(*this);
			this->child2->val1=new T(*temp->val3);
			this->child2->key1=temp->key3;
			this->child2->val2=NULL;
			this->child2->val3=NULL;
			this->child2->key2=0;
			this->child2->key3=0;
			if (temp->child1!=NULL)
			{
				this->child2->child1=new Node<T>(*temp->child3);
				this->child2->child1->parent=this->child2;
				this->child2->child2=new Node<T>(*temp->child4);
				this->child2->child2->parent=this->child2;
				this->child2->child3=NULL;
				this->child2->child4=NULL;
			}
		if (this->child3!=NULL) this->child3->parent=this->child4->parent=NULL;
		this->child3=this->child4=NULL;
		this->child1->parent=this;
		this->child2->parent=this;
		
		temp->child1=temp->child2=temp->child3=temp->child4=temp->parent=NULL;
		delete temp;
		return;
	}
	//==============================================================================
	//==============================================================================
	if (parent != NULL && val3!=NULL)
	{
		if (parent->child1==this)
		{
			Node<T> * temp1=new Node<T>;
			(*temp1)=(*parent);
			(*this)=(*temp1);
			if (temp1->parent!=NULL)
			{
				if (temp1->parent->child1==temp1) this->parent->child1=this;
				if (temp1->parent->child2==temp1) this->parent->child2=this;
				if (temp1->parent->child3==temp1) this->parent->child3=this;
				if (temp1->parent->child4==temp1) this->parent->child4=this;
			}
			temp1->child1=temp->child2=temp1->child3=temp1->child4=temp1->parent=NULL;
			delete temp1;
			//--------------------------------------
			if (this->val2!=NULL)
			{
				this->val3=new T(*this->val2);
				this->key3=this->key2;
				this->child4=new Node<T>(*parent->child3);
			}
			else
			{
				this->val3=NULL;
				this->key3=0;
				this->child4=NULL;
			}
			this->val2=new T(*this->val1);
			this->key2=this->key1;
			this->child3=new Node<T>(*this->child2);
			this->val1=new T(*temp->val2);
			this->key1=temp->key2;
				//-----------------------------------
				this->child1->val1=new T(*temp->val1);
				this->child1->key1=temp->key1;
				this->child1->val2=NULL;
				this->child1->val3=NULL;
				this->child1->key2=0;
				this->child1->key3=0;
				if (temp->child1!=NULL)
				{
					this->child1->child1=new Node<T>(*temp->child1);
					this->child1->child1->parent=this->child1;
					this->child1->child2=new Node<T>(*temp->child2);	
					this->child1->child2->parent=this->child1;
					this->child1->child3=NULL;
					this->child1->child4=NULL;
				}
				//--------------------------------------
				this->child2->val1=new T(*temp->val3);
				this->child2->key1=temp->key3;
				this->child2->val2=NULL;
				this->child2->val3=NULL;
				this->child2->key2=0;
				this->child2->key3=0;
				if (temp->child1!=NULL)
				{
					this->child2->child1=new Node<T>(*temp->child3);
					this->child2->child1->parent=this->child2;
					this->child2->child2=new Node<T>(*temp->child4);
					this->child2->child2->parent=this->child2;
					this->child2->child3=NULL;
					this->child2->child4=NULL;
				}
			//------------------------------------------------
			this->child1->parent=this;
			this->child2->parent=this;

			temp->child1=temp->child2=temp->child3=temp->child4=temp->parent=NULL;
			delete temp;
			return;
		}
		//========================================================================
		if (parent->child2==this)
		{
			Node<T> * temp1=new Node<T>;
			(*temp1)=(*parent);
			(*this)=(*temp1);
			if (temp1->parent!=NULL)
			{
				if (temp1->parent->child1==temp1) this->parent->child1=this;
				if (temp1->parent->child2==temp1) this->parent->child2=this;
				if (temp1->parent->child3==temp1) this->parent->child3=this;
				if (temp1->parent->child4==temp1) this->parent->child4=this;
			}
			temp1->child1=temp1->child2=temp1->child3=temp1->child4=temp1->parent=NULL;
			delete temp1;
			//----------------------------------------------
			if (this->val2!=NULL)
			{
				this->val3=new T(*this->val2);
				this->key3=this->key2;
				this->child4=new Node<T>(*this->child3);
			}
			else
			{
				this->val3=NULL;
				this->key3=0;
				this->child4=NULL;
			}
			this->val2=new T(*temp->val2);
			this->key2=temp->key2;
				//-----------------------------------------
				this->child2->val1=new T(*temp->val1);
				this->child2->key1=temp->key1;
				this->child2->val2=NULL;
				this->child2->val3=NULL;
				this->child2->key2=0;
				this->child2->key3=0;
				if (temp->child1!=NULL)
				{
					this->child2->child1=new Node<T>(*temp->child1);
					this->child2->child1->parent=this->child2;
					this->child2->child2=new Node<T>(*temp->child2);
					this->child2->child2->parent=this->child2;
					this->child2->child3=NULL;
					this->child2->child4=NULL;
				}
				//------------------------------------------
				this->child3=new Node<T>;
				this->child3->val1=new T(*temp->val3);
				this->child3->key1=temp->key3;
				this->child3->val2=NULL;
				this->child3->val3=NULL;
				this->child3->key2=0;
				this->child3->key3=0;
				if (temp->child1!=NULL)
				{
					this->child3->child1=new Node<T>(*temp->child3);
					this->child3->child1->parent=this->child3;
					this->child3->child2=new Node<T>(*temp->child4);
					this->child3->child2->parent=this->child3;
					this->child3->child3=NULL;
					this->child3->child4=NULL;
				}
			//----------------------------------------------
			this->child2->parent=this;
			this->child3->parent=this;

			temp->child1=temp->child2=temp->child3=temp->child4=temp->parent=NULL;
			delete temp;
			return;
		}
		//======================================================================
		if (parent->child3==this)
		{
			Node<T> * temp1=new Node<T>;
			(*temp1)=(*parent);
			(*this)=(*temp1);
			if (temp1->parent!=NULL)
			{
				if (temp1->parent->child1==temp1) this->parent->child1=this;
				if (temp1->parent->child2==temp1) this->parent->child2=this;
				if (temp1->parent->child3==temp1) this->parent->child3=this;
				if (temp1->parent->child4==temp1) this->parent->child4=this;
			}
			temp1->child1=temp1->child2=temp1->child3=temp1->child4=temp1->parent=NULL;
			delete temp1;
			this->val3=new T(*temp->val2);
			this->key3=temp->key2;
				//-----------------------------------------
				this->child3->val1=new T(*temp->val1);
				this->child3->key1=temp->key1;
				this->child3->val2=NULL;
				this->child3->val3=NULL;
				this->child3->key2=0;
				this->child3->key3=0;
				if (temp->child1!=NULL)
				{
					this->child3->child1=new Node<T>(*temp->child1);
					this->child3->child1->parent=this->child3;
					this->child3->child2=new Node<T>(*temp->child2);
					this->child3->child2->parent=this->child3;
					this->child3->child3=NULL;
					this->child3->child4=NULL;
				}
				//-------------------------------------------------
				this->child4=new Node<T>;
				this->child4->val1=new T(*temp->val3);
				this->child4->key1=temp->key3;
				this->child4->val2=NULL;
				this->child4->val3=NULL;
				this->child4->key2=0;
				this->child4->key3=0;
				if (temp->child1!=NULL)
				{
					this->child4->child1=new Node<T>(*temp->child3);
					this->child4->child1->parent=this->child4;
					this->child4->child2=new Node<T>(*temp->child4);
					this->child4->child2->parent=this->child4;
					this->child4->child3=NULL;
					this->child4->child4=NULL;
				}
			//---------------------------------------------------------------
			this->child3->parent=this;
			this->child4->parent=this;
			
			temp->child1=temp->child2=temp->child3=temp->child4=temp->parent=NULL;
			delete temp;
			return;
		}
	}
}

template<class T>
class Tree
{
		Node<T> * root;
	public:
		Tree();
		void push (const T & value_, const int & key);
		void pop (const int & key);
		void direct_ord_out(ostream & s=cout);
		void inverse_ord_out(ostream & s=cout);
		void symm_ord_out(ostream & s=cout);
		bool symmetric_swap(const int & key);
		T& find(const int & key);
		~Tree();
};

template<class T>
Tree<T>::Tree()
{
	root=NULL;
}

template<class T>
void Tree<T>::push(const T & value, const int & key)//<=
{
	if (root == NULL)//case empty tree
	{
		root = new Node<T>;
		root->val1=new T(value);
		root->key1=key;
		root->child1=NULL;
		root->child2=NULL;
		root->child3=NULL;
		root->child4=NULL;
		root->parent=NULL;
		return;
	}
	else
	{
		Node<T> * x;
		x=root;
		bool ok=false;
		Node<T> * t;
		while (!ok)
		{
			if (x->val1!=NULL && x->val2!=NULL && x->val3!=NULL)
			{
				x->split();
				t=x;
				while (t->parent!=NULL)
					t=t->parent;
				root=t;
			}
			if (x->child1==NULL)
				ok = true;
			if (key<x->key1 && x->child1!=NULL)
			{
				x=x->child1;
				continue;
			}
			if (key>x->key1 && (x->key2==0 || key<x->key2) && x->child2!=NULL)
			{
				x=x->child2;
				continue;
			}
			if (key>x->key2 && (x->key3==0 || key<x->key3) && x->child3!=NULL)
			{
				x=x->child3;
				continue;
			}
			if (key>x->key3 && x->child4!=NULL)
			{
				x=x->child4;
				continue;
			}
		}
		if (x->val2!=NULL)
		{
			if (key>x->key2)
			{
				x->val3=new T(value);
				x->key3=key;
			}
			else
				if (key<=x->key2 && key> x->key1)
				{
					x->val3=x->val2;
					x->key3=x->key2;
					x->val2=new T(value);
					x->key2=key;
				}
				else
					if (key<=x->key1)
					{
						x->val3=x->val2;
						x->key3=x->key2;
						x->val2=x->val1;
						x->key2=x->key1;
						x->val1=new T(value);
						x->key1=key;
					}
		}
		else
		{
			if (key>x->key1)
			{
				x->val2=new T;
				*(x->val2) = value;
				x->key2=key;
			}
			else
				if (key<=x->key1)
				{
					x->val2=x->val1;
					x->key2=x->key1;
					x->val1=new T(value);
					x->key1=key;
				}
		}
	}
}

template<class T>
void Node<T>::swap(const int & key)
{
	Node<T> * x;
	x=this;
	static bool ok=false;
	if (x->child1==NULL)
	{
		if (x->parent->val3!=NULL)
		{
			if (x->parent->child1->val2==NULL) x->parent->child1->val2=new T(*x->parent->val1);
			else
				if (x->parent->child1->val3==NULL) x->parent->child1->val3=new T(*x->parent->val1);
			if (x->parent->child1->key2==0) x->parent->child1->key2=x->parent->key1;
			else
				if (x->parent->child1->key3==0) x->parent->child1->key3=x->parent->key1;
			(*x->parent->val1)=(*x->parent->val2);
			(*x->parent->val2)=(*x->parent->val3);
			x->parent->val3=NULL;
			x->parent->key1=x->parent->key2;
			x->parent->key2=x->parent->key3;
			x->parent->child2=x->parent->child3;
			x->parent->child3=x->parent->child4;
			x->parent->child4=NULL;
			x->parent->key3=0;
			x->parent=NULL;
			delete x;
		}
		else
			if (x->parent->val2!=NULL)
			{
				if (x->parent->child1->val2==NULL) x->parent->child1->val2=new T(*x->parent->val1);
				else
					if (x->parent->child1->val3==NULL) x->parent->child1->val3=new T(*x->parent->val1);
				if (x->parent->child1->key2==NULL) x->parent->child1->key2=x->parent->key1;
				else
					if (x->parent->child1->key3==NULL) x->parent->child1->key3=x->parent->key1;
				(*x->parent->val1)=(*x->parent->val2);
				x->parent->val2=NULL;
				x->parent->key1=x->parent->key2;
				x->parent->key2=0;
				x->parent->child2=x->parent->child3;
				x->parent->child3=NULL;
				x->parent=NULL;
				delete x;
			}
			else
				if (x->parent->val1!=NULL)
				{
					if (x->parent->child1->val2!=NULL)
					{
						if (x->parent->child1->val3!=NULL)
						{
							(*x->val1)=(*x->parent->val1);
							x->key1=x->parent->key1;
							(*x->parent->val1)=(*x->parent->child1->val3);
							x->parent->child1->val3=NULL;
							x->parent->key1=x->parent->child1->key3;
							x->parent->child1->key3=0;
						}
						else
						{
							(*x->val1)=(*x->parent->val1);
							x->key1=x->parent->key1;
							(*x->parent->val1)=(*x->parent->child1->val2);
							x->parent->child1->val2=NULL;
							x->parent->key1=x->parent->child1->key2;
							x->parent->child1->key2=0;
						}
					}
					else
					{
						(*x->parent->val2)=(*x->parent->val1);
						x->parent->key2=x->parent->key1;
						(*x->parent->val1)=(*x->parent->child1->val1);
						x->parent->key1=x->parent->child1->key1;
						Node<T> * t1;
						Node<T> * t2;
						t1=x->parent->child1;
						t2=x;
						x->parent->child1=NULL;
						x->parent->child2=NULL;
						t1->parent=NULL;
						t2->parent=NULL;
						x=NULL;
						delete t1;
						delete t2;
					}
				}
		ok=true;
	}
	T temp;
	int copy;
	if (key==x->key1)
	{
		temp=(*x->val1);
		copy=x->key1;
		(*x->val1)=(*x->child2->val1);
		x->key1=x->child2->key1;
		(*x->child2->val1)=temp;
		x->child2->key1=copy;
		x=x->child2;
	}
	else
		if (key==x->key2)
		{
			temp=(*x->val2);
			copy=x->key2;
			(*x->val2)=(*x->child3->val1);
			x->key2=x->child3->key1;
			(*x->child3->val1)=temp;
			x->child3->key1=copy;
			x=x->child3;
		}
		else
			if (key==x->key3)
			{
				temp=(*x->val3);
				copy=x->key3;
				(*x->val3)=(*x->child4->val1);
				x->key3=x->child4->key1;
				(*x->child4->val1)=temp;
				x->child4->key1=copy;
				x=x->child4;
			}
	if (ok==false) x->swap(key); else ok=true;
}

template<class T>
void Tree<T>::pop(const int & key)
{
	Node<T> * x;
	x=root;
	bool find=false;
	while(!find)
	{
		if (x->key1==key) break;
		if (x->key2==key) break;
		if (x->key3==key) break;
		if (key<x->key1 && x->child1!=NULL)
			x=x->child1;
		else
			if (key>x->key1 && (x->key2==0 || key<x->key2) && x->child2!=NULL)
				x=x->child2;
			else
				if (key>x->key2 && (x->key3==0 || key<x->key3) && x->child3!=NULL)
					x=x->child3;
				else
					if (key>x->key3 && x->child4!=NULL)
						x=x->child4;
					else return;
	}
	x->swap(key);
}

template<class T>
void Tree<T>::direct_ord_out(ostream & s)
{
	root->direct_ord_out(s);
}

template<class T>
void Tree<T>::inverse_ord_out(ostream & s)
{
	root->inverse_ord_out(s);
}

template<class T>
void Tree<T>::symm_ord_out(ostream & s)
{
	root->symm_ord_out(s);
}

template<class T>
T& Tree<T>::find(const int & key)
{
	Node<T> * x;
	x=root;
	bool find=false;
	while(!find)
	{
		if (x->key1==key) return (*x->val1);
		if (x->key2==key) return (*x->val2);
		if (x->key3==key) return (*x->val3);
		if (key<x->key1 && x->child1!=NULL)
			x=x->child1;
		else
			if (key>x->key1 && (x->key2==0 || key<x->key2) && x->child2!=NULL)
				x=x->child2;
			else
				if (key>x->key2 && (x->key3==0 || key<x->key3) && x->child3!=NULL)
					x=x->child3;
				else
					if (key>x->key3 && x->child4!=NULL)
						x=x->child4;
					else
					{
						T * value=new T(NULL); 
						return (*value);
					}
	}
}

template<class T>
Tree<T>::~Tree()
{
	root->del();
}

#endif