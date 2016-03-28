#ifndef CLASS_RED_BLACK_TREE
#define CLASS_RED_BLACK_TREE

#include <iostream>
using namespace std;

#ifndef DEBUG
#define assert(x)
#else
#define assert(x) if(!x){\
	cout<<endl<<#x<<endl;cout<<"line:"<<__LINE__<<endl<<"file:"<<__FILE__<<endl;\
	cin.get();\
	exit(0);}
#endif

enum Color{Black,Red};

template <class T>
class RBTree
{
	struct Node
	{
		T * value;
		int key;
		Node *left,*right,*parent;
		Color color;
		void del();
		void direct_ord_out(ostream &s = cout);
		void symm_ord_out(ostream &s = cout);
		void inverse_ord_out(ostream &s = cout);
		T& find(const int & key_);
		Node* push(const T& val, const int & key_);
	};
	Node * root;
	void left_rotation(Node *x);
	void right_rotation(Node *x);
	void fixup(Node *x);//після видалення
public:
	RBTree();
	void push(const T & val, const int & key_);
	void pop(const int & key_);
	T& find(const int & key_);
	void direct_ord_out(ostream &s = cout);
	void symm_ord_out(ostream &s = cout);
	void inverse_ord_out(ostream &s = cout);
	~RBTree();
};

template <class T>
T& RBTree<T>::Node::find(const int & key_)
{
	if(key == key_)
		return (*value);
	if(key_<key)
	{
		if(left == NULL)
		{
			T * value_=new T(NULL);
			return (*value);
		}
		return left->find(key_);
	}
	else 
	{
		if(right == NULL)
		{
			T * value_=new T(NULL);
			return (*value);
		}
		return right->find(key_);
	}
}

template <class T>
typename RBTree<T>::Node* RBTree<T>::Node::push(const T & val, const int & key_)
{
	if(key_<key)
	{
		if(left == NULL)
		{
			left = new Node;
			left->value = new T(val);
			left->key = key_;
			left->right=left->left=NULL;
			left->parent = this;
			return left;
		}
		left->push(val,key_);
	}
	else 
	{
		if(right == NULL)
		{
			right = new Node;			
			right->value = new T(val);
			right->key = key_;
			right->right = right->left=NULL;
			right->parent = this;
			return right;
		}
		right->push(val, key_);
	}
}

template <class T>
T& RBTree<T>::find(const int & key_)
{
	return root->find(key_);
}

template <class T>
void RBTree<T>::Node::direct_ord_out(ostream &s)
{
	if(value != NULL)
		s<<(*value)<<endl;
	if(left !=NULL)
		left->direct_ord_out(s);
	if(right != NULL)
		right->direct_ord_out(s);
}

template <class T>
void RBTree<T>::Node::symm_ord_out(ostream &s)
{
	if(left !=NULL)
		left->symm_ord_out(s);
	if(value != NULL)
		s<<(*value)<<endl;
	if(right != NULL)
		right->symm_ord_out(s);
}

template <class T>
void RBTree<T>::Node::inverse_ord_out(ostream &s)
{
	if(left !=NULL)
		left->inverse_ord_out(s);
	if(right != NULL)
		right->inverse_ord_out(s);
	if(value != NULL)
		s<<(*value)<<endl;
}

template <class T>
void RBTree<T>::Node::del()
{
	if(left != NULL)
		delete left;
	if(right != NULL)
		delete right;
	if(parent!=NULL)
		if(parent->left != NULL && parent->left->key == key)
			parent->left = NULL;
		else
			if(parent->right != NULL &&parent->right->key == key)
				parent->right = NULL;
	left = right = parent = NULL;
}


template <class T>
RBTree<T>::RBTree()
{
	root = NULL;
}

template <class T>
void RBTree<T>::left_rotation(Node *x)
{
	Node * y = x->right;
	x->right = y->left;
	if (y->left != NULL) y->left->parent = x;
	y->parent = x->parent;
	if (x->parent)
	{
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else root = y;
	y->left = x;
	x->parent = y;
}

template <class T>
void RBTree<T>::right_rotation(Node *x)
{
	Node *y = x->left;
	x->left = y->right;
	if (y->right!=NULL) y->right->parent = x;
	y->parent = x->parent;
	if (x->parent)
	{
		if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
	}
	else root = y;
	y->right = x;
	x->parent = y;
}

template <class T>
void RBTree<T>::fixup(Node* x)
{
    while (x != root && x->color == Black)
	{
		if (x == x->parent->left)
		{
			Node * w = x->parent->right;
			if (w == NULL) break;
			if (w->color == Red)
			{
				w->color = Black;
				x->parent->color = Red;
				left_rotation (x->parent);
				w = x->parent->right;
			}
			if (w->left!=NULL && w->left->color == Black && w->right->color == Black)
			{
				w->color = Red;
				x = x->parent;
			}
			else
			{
				if (w->right!=NULL && w->right->color == Black)
				{
					w->left->color = Black;
					w->color = Red;
					right_rotation (w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = Black;
				if (w->right != NULL) w->right->color = Black;
				left_rotation (x->parent);
				x = root;
           }
		}
		else 
		{
			Node *w = x->parent->left;
			if (w == NULL) break;
			if (w->color == Red)
			{
				w->color = Black;
				x->parent->color = Red;
				right_rotation(x->parent);
				w = x->parent->left;
			}
			if (w->right == NULL) break;
			if (w->right->color == Black && w->left->color == Black)
			{
				w->color = Red;
				x = x->parent;
			}
			else
			{
				if (w->left->color == Black)
				{
					w->right->color = Black;
					w->color = Red;
					left_rotation (w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = Black;
				w->left->color = Black;
				right_rotation (x->parent);
				x = root;
			}
		}
	}
    x->color = Black;
}

template <class T>
void RBTree<T>::push(const T& val, const int & key_)
{
	if(root == NULL)
	{
		root = new Node;
		root->value = new T(val);
		root->key = key_;
		root->parent = NULL;
		root->right = NULL;
		root->left = NULL;
		root->color = Red;
		return;
	}
	Node *x = root->push(val, key_);
	x->color = Red;
	if(x->parent->parent!=NULL)
	{
		while(x!=root && x->parent->color == Red)
		{
			if (x->parent == x->parent->parent->left)
			{
				Node *y = x->parent->parent->right;
				if (y!= NULL && y->color == Red)
				{
					x->parent->color = Black;
					y->color = Black;
					x->parent->parent->color = Red;
					x = x->parent->parent;
				}
				else
				{
					if (x == x->parent->right)
					{
						x = x->parent;
						left_rotation(x);
					}
					x->parent->color = Black;
					x->parent->parent->color = Red;
					right_rotation(x->parent->parent);
				}
			}
			else
			{
				Node *y = x->parent->parent->left;
				if (y!= NULL && y->color == Red)
				{
				    x->parent->color = Black;
					y->color = Black;
					x->parent->parent->color = Red;
					x = x->parent->parent;
				}
				else
				{
					if (x == x->parent->left)
					{
					    x = x->parent;
						right_rotation(x);
					}
					x->parent->color = Black;
					if(x->parent->parent!=NULL)
					{
						x->parent->parent->color = Red;
						left_rotation(x->parent->parent);
					}
				}
			}
		}
		root->color = Black;//*/}
	}
}

template <class T>
void RBTree<T>::direct_ord_out(ostream &s = cout)
{
	root->direct_ord_out(s);
}

template <class T>
void RBTree<T>::symm_ord_out(ostream &s = cout)
{
	root->symm_ord_out(s);
}

template <class T>
void RBTree<T>::inverse_ord_out(ostream &s = cout)
{
	root->inverse_ord_out(s);
}

template <class T>
void RBTree<T>::pop(const int & key_)
{
	Node *z=root;
	Node *y;
	while(z->key !=key_)
		if(key_<z->key)
			if(z->left !=NULL)
				z = z->left;
			else return;
		else 
			if(z->right !=NULL)
			z = z->right;
			else return;
	if(z->left == NULL && z->right == NULL)
	{
		z->del();
		delete z;
		return;
	}
	if(z->left == NULL || z->right == NULL)
		y=z;
	else
	{
		if(z->right != NULL)
		{
			y=z->right;
			if(y!=NULL)
				while(y->left!=NULL)
					y=y->left;
		}
		else
		{
			Node * temp = z;
			y= temp->parent;
			while(y!=NULL || temp==y->right)
			{
				temp=y;
				y=y->parent;
			}
		}
		(*z->value)=(*y->value);
		z->key=y->key;
	}
	if(y->left)
		z = y->left;
	else 
		z = y->right;
	if(z==NULL)
	{
		z=new Node;
		z->left = z->right = z->parent = NULL;
	}
	z->parent = y->parent;
	if(y->parent)
	{
		if(y==y->parent->left)
			y->parent->left = z;
		else 
			y->parent->right = z;
	}
	else root = z;
	if(y!=z)
	{
		(*z->value) = (*y->value);
		z->key=y->key;
		z->color = y->color;
	}
	if(y->color == Black)
		fixup(z);
	y->right = NULL;
	y->left = NULL;
	y->del();
	delete y;
	return;
}

template <class T>
RBTree<T>::~RBTree()
{
	root->del();
}

#endif