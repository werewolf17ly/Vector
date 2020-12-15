#include "vector2.h"

vector2::vector2(int s) 
	:sz{ s }, 
	elem{ new double[s] }
{
	for (int i = 0; i < s; ++i)
	{
		elem[i] = 0;
	}
}

vector2::vector2(std::initializer_list<double> lst)
	:sz{ static_cast<int>(lst.size()) },
	elem{ new double[static_cast<int>(lst.size())] }
{
	std::copy(lst.begin(), lst.end(), elem);
}

vector2::vector2(const vector2& arg)
	:sz{ arg.sz },
	elem{ new double[arg.sz] }
{
	std::copy(arg.elem, arg.elem + sz, elem);
}

vector2& vector2::operator=(const vector2& a)
{
	double* p = new double[a.sz];
	std::copy(a.elem, a.elem + a.sz, p);
	delete[] elem;
	elem = p;
	sz = a.sz;
	return *this;
}

vector2::vector2(vector2&& a)
	:sz{ a.sz },
	elem{ a.elem }
{
	a.sz = 0;
	a.elem = nullptr;
}

vector2& vector2::operator=(vector2&& a)
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	a.elem = nullptr;
	a.sz = 0;
	return *this;
}