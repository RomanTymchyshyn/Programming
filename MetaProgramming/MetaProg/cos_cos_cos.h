#include"cos_x.h"
template<int X, int I, int N, int i=1, int j=1>
struct COSCOS
{
	enum { go1 = i<I, go2 = (j+1 <= N)};
	static inline float f()
	{
		return 1.0 - COSCOS<X*go2,I*go2, N*go2, i*go2, (j+2)*go2>::f()/float(j*(j+1))*COSCOS<X, I*go1, N*go1,(i+1)*go1,1*go1>::f();
	};
};

template<int X>
struct COSCOS<X,0,0,0,0>
{
	static inline float f()
	{
		return sqrt(float(X));
	};
};

template<>
struct COSCOS<0,0,0,0,0>
{
	static inline float f()
	{
		return 0;
	}
};