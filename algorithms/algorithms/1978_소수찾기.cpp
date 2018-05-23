#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	int num[101] = { 0, };
	int cnt = 0;
	int i, j;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	bool flag;
	for (i = 0; i < n; i++)
	{
		if (num[i] == 1)
			flag = false;
		else
			flag = true;
		for (j = 2; j <= sqrt(num[i]); j++)
		{
			if (num[i] % j == 0)
				flag = false;
		}

		if (flag)
			cnt++;
	}

	cout << cnt << endl;
	system("pause");
	return 0;
}