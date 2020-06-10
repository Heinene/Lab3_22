#include <iostream>
#include "Vector.h"
using namespace std;


int main()
{
	int n;
	cin >> n;

	double* m = new double[n];
	for (int i = 0; i < n; i++)
	cin >> m[i];
	v V1(n, m);
	double* z = new double[n];
	for (int i = 0; i < n; i++)
		cin >> z[i];
	v V2;
	V2 = z * V1;
	cout << V2;
	return 0;
}