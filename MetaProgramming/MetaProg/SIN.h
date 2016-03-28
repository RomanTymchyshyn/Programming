#pragma once
#include"COS.h"

template<int N, int I, int i=1, int j=1>
struct SIN
{
	enum { go = i + 1 <= I, go2=(j+1!=100)};
	static inline float f()
	{
		return float(COS<N,100,1>::f()) - (float(COS<N,100,1>::f()*COS<N,100,1>::f()) / float((j+2)*(j+1)))*SIN<N, I*go2,(i+1)*go2,(j+2)*go2>::f();
	}
};

template<int N>
struct SIN<N,0,0,0>
{
	static inline float f()
	{
		return COS<N,100>::f();
	}
};

template<>
struct SIN<0,0,0,0>
{
	static inline float f()
	{
		return 0;
	}
};