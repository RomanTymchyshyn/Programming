#ifndef CLASS_BIN_TREE
#define CLASS_BIN_TREE

#include <stdio.h>
#include <iostream>

using namespace std;

template<class T>
class binTree
{
		binTree * left;
		binTree * right;
	public:
		T * value;
		binTree();
		void push (const T & value);
		void pop (const T & value, binTree * parent=NULL);
		void direct_ord_out(ostream & s=cout);
		void inverse_ord_out(ostream & s=cout);
		void symm_ord_out(ostream & s=cout);
		bool find(const T & value_, binTree ** parent);
		bool find(const T & value_);
		void del();
		~binTree();
};

template<class T>
binTree<T>::binTree()
{
	left=right=NULL;
	value=NULL;
}

template<class T>
void binTree<T>::push(const T & value_)
{
	if (value==NULL)
	{
		value=new T(value_);
		return;
	}
	if (value_<(*value))
	{
		if (left == NULL) left=new binTree;
		left->push(value_);
	}
	else
	{
		if (right==NULL) right=new binTree;
		right->push(value_);
	}
}

template<class T>
void binTree<T>::pop(const T & value_, binTree * parent)
{
	if (value == NULL) return;

	if(value_ == (*value))
	{
		if(left == NULL && right == NULL)//видаляємо лист
		{
			if (parent == NULL)
				this->del();
			else 
				if (*(parent->left->value) == value_)
				{
					delete parent->left;
					parent->left = NULL;
				}
				else 
					if(*(parent->right->value) == value_)
					{
						delete parent->right;
						parent->right = NULL;
					}
		}
		else 
			if (left != NULL && right == NULL)
			{
				if(parent->left != NULL && *(parent->left->value) == value_)
				{
					parent->left = left;
					left = NULL;
					delete this;
				}
				else 
					if (parent->right!= NULL && *(parent->right->value) == value_)
					{
						parent->right = left;
						left = NULL;
						delete this;
					}
			}
			else 
				if (right != NULL && left == NULL)
				{
					if(parent == NULL)
					delete this;
					if(parent->left!=NULL && *(parent->left->value) == value_)
					{
						parent->left = right;
						right = NULL;
						delete this;
					}
					else 
						if(parent->right != NULL && *(parent->right->value) == value_)
						{
							parent->right = right;
							right = NULL;
							delete this;
						}
				}
				else
				{
					binTree<T> * temp;
					parent = this;
					temp = right;
					while(temp->left != NULL)
					{
						parent = temp;
						temp = temp->left;
					}
					*value = *(temp->value);
					parent->pop(*value);
				}
	}
	else 
		if(value_<(*value))
		{
			if(left == NULL) return;
			parent = this;
			left->pop(value_,parent);
		}
	else
	{
		if (right == NULL) return;
		parent = this;
		right->pop(value_,parent);
	}
}

template<class T>
void binTree<T>::direct_ord_out(ostream & s)
{
	if(value != NULL)
		s<<(*value)<<endl;
	if(left !=NULL)
		left->direct_ord_out(s);
	if(right != NULL)
		right->direct_ord_out(s);
}

template<class T>
void binTree<T>::symm_ord_out(ostream & s)
{
	if(left !=NULL)
		left->symm_ord_out(s);
	if(value != NULL)
		s<<(*value)<<endl;
	if(right != NULL)
		right->symm_ord_out(s);
}

template<class T>
void binTree<T>::inverse_ord_out(ostream & s)
{
	if(left !=NULL)
		left->inverse_ord_out(s);
	if(right != NULL)
		right->inverse_ord_out(s);
	if(value != NULL)
		s<<(*value)<<endl;
}

template<class T>
bool binTree<T>::find(const T & value_, binTree ** parent)
{
	if (value==NULL) return false;
	if (value_==(*value)) return true;
	if (value_<(*value))
	{
		*parent=left;
		if (*parent==NULL) return false;
		return (*parent)->find(value_, parent);
	}
	else
	{
		*parent=right;
		if (*parent==NULL) return false;
		return (*parent)->find(value_, parent);
	}
}

template<class T>
bool binTree<T>::find(const T & value_)
{
	if (value==NULL) return false;
	if (value_==(*value)) return true;
	if (value_<(*value))
	{
		if (left==NULL) return false;
		return left->find(value_);
	}
	else
	{
		if (right==NULL) return false;
		return right->find(value_);
	}
}

template<class T>
void binTree<T>::del()
{
	if(left != NULL)
		delete left;
	if(right != NULL)
		delete right;
	if(value != NULL)
		delete value;
	left = right = NULL;
	value = NULL;
}

template<class T>
binTree<T>::~binTree()
{
	del();
}

#endif