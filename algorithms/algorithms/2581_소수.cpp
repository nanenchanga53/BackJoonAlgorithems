#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n, m;
	int cnt = 0;
	int sum = 0;
	int first = 0;
	int i, j;
	cin >> m >> n;

	bool flag;
	for (i = m; i <= n; i++)
	{
		if (i == 1)
			flag = false;
		else
			flag = true;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
				flag = false;
		}

		if (flag)
		{
			sum += i;
			if (first == 0)
				first = i;
		}
	}

	if (first == 0)
		cout << -1 << endl;
	else
	{
		cout << sum << endl;
		cout << first << endl;
	}
	system("pause");
	return 0;
}