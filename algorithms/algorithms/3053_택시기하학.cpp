#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double n;
	cin >> n;
	cout << fixed;
	cout.precision(6);
	cout << M_PI * n * n << endl;
	cout << 2 * n * n << endl;

	return 0;
}