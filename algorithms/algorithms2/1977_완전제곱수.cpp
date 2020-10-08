#include <iostream>
using namespace std;



int main()
{
	int firstPass = 0;
	int d,m,n;
	long long sum;
	cin >> m >> n;
	sum = 0;
	for (int i = 1; i <= 101; i++)
	{
		d = i * i;
		if (d >= m && d <= n)
		{
			if (firstPass == 0)
			{
				firstPass = d;
			}
			sum += d;
		}
	}
	if (firstPass == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << sum << endl << firstPass << endl;
	}
	system("pause");
	return 0;
}