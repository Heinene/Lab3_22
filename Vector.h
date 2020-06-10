#pragma once
#include<iostream>
using namespace std;

class v
{
	double* a; 
	int n; 

public:
	v(int n, double* a);
	v(const v& V);
	v(v&& V);
	v();
	double& operator[](int dat);
	v& operator =(v& v2);
	friend ostream& operator <<(ostream& o, v& vect);
	~v();
	friend v& operator*(double* x, v& vect);
};