#include "Vector.h"
#include <iostream>


v::v() 
{
	a = nullptr;
	n = 0;
}
v::v(int n, double* a)
{
	this->n = n; 
	this->a = new double[n]; 
	for (int i = 0; i < n; i++) this->a[i] = a[i]; 
}
v::v(const v& vect)
{ 
	n = vect.n;
	a = new double[n];
	for (int i = 0; i < n; i++)
		a[i] = vect.a[i];
}
v::v(v&& vect)  
	: a(nullptr)
	, n(vect.n)
{
	a = new double[n];
	memcpy(a, vect.a, n);
}
double& v::operator[](int i)
{
	return a[i];
}
v& v::operator =(v& vect)  
{
	n = vect.n;
	if (a != nullptr) delete[] a;
	a = new double[n]; 
	for (int i = 0; i < n; i++) a[i] = vect.a[i];
	return *this; 
}
v::~v() 
{
	if (a != nullptr) delete[] a; 
}
std::ostream& operator<<(v& vect, ostream& out)
{
	for (int i = 0; i < vect.n; i++)
		out << vect.a[i] << " ";
	out << endl;
	return out;
}
v& operator*(v& vect, double* x) {
	double* a = new double[vect.n]; 
	for (int i = 0; i < vect.n; i++) a[i] = x[i] * vect.a[i]; 
	v* pV = new v(a, vect.n);
	delete[] a; 
	return *pV; 
}