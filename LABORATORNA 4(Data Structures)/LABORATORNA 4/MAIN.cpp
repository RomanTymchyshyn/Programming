#include <iostream>
#include <cstdlib>
#include "LINKED_LIST.h"
#include "VECTOR.h"
#include "DOUBLE_LIST.h"
#include "QUEUE.h"
#include "DEQUEUE.h"
#include "BINARY.h"
#include "SORT.h"
#include "STACK.h"
#include "2_3_4_TREE.h"
#include "RED_BLACK_TREE.h"

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(7);
	v.push_back(3);
	v.push_back(8);
	v.push_back(10);
	v.BetcherSort();
	system("pause");
	return 0;
}