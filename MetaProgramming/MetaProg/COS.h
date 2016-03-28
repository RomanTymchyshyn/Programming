#pragma once
#include"EXP.h"
template<int N, int I, int i=1>
struct COS
{
	enum { go = i + 1 <= I};
	static inline float f()
	{
		return 1.0 - (float(ExpExp<N,1,1,1>::f()*ExpExp<N,1,1,1>::f()) / float(i*(i+1)))*COS<N*go, I*go, (i+2)*go>::f();
	};
};

template<>
struct COS<0,0,0>
{
	static inline float f()
	{
		return 0;//SIN<2,100>::f();
	};
};