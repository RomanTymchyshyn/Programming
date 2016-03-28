#pragma once
#include"SIN.h"
template<int N,int I,int i=1,int j = 1>
struct ExpExp
{
	enum{go1 = (i < I),go2 = (j+1 != 200)};
	static inline double f()
	{
		return 1. + (float)ExpExp<N,I*go1,(i+1)*go1,1*go1>::f()/j * ExpExp<N*go2,I*go2,i*go2,(j+1)*go2>::f();
	}
};

template<int N>
struct ExpExp<N,0,0,0>
{
	static inline double f()
	{
		/*	if need more funcs in recurtion should call from here	*/
		return SIN<N,100>::f();
	}
};

template<>
struct ExpExp<0,0,0,0>
{
	static inline double f()
	{
		return 0;
	}
};