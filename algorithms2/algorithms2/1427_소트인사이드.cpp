#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	long long n;
	long long num[11] = { 0, };
	cin >> n;
	do
	{
		num[n % 10]++;
		n /= 10;
	} while (n > 0);

	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < num[i]; j++)
			cout << i;
	system("pause");
}