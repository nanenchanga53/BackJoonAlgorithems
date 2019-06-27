#include<iostream>
#include<cmath>
using namespace std;

long long nPibonachi(int& n)
{
	if (n == 1 || n == 2) return 1;
	else if (n == 0) return 0;

	long long nowNum = 1, lastNum = 1, newNum = 0;

	for (int i = 3; i <= n; i++)
	{
		newNum = nowNum + lastNum;
		lastNum = nowNum;
		nowNum = newNum;
	}
	return newNum;
}

int main()
{
	int i, n;

	int pibo[46] = { 0,1,1, };

	for (int i = 3; i <= 45; i++)
		pibo[i] = pibo[i - 1] + pibo[i - 2];

	cin >> n;

	cout << pibo[n] << endl;

	return 0;
}