#include<iostream>
using namespace std;

int Factorial(int n)
{
	int cnt = 1;
	for (int i = 1; i <= n; i++)
		cnt *= i;
	return cnt;
}

int main()
{
	int n;
	cin >> n;

	cout << Factorial(n) << endl;
	return 0;
}