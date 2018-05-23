#include<iostream>
#include<cstring>
using namespace std;

#define MAX_NUM 10001

bool num[MAX_NUM] = { false, };

void arato()
{
	int i, j;
	memset(num, true, num[0] + MAX_NUM);

	num[1] = false;
	for (i = 2; i < MAX_NUM; i++)
	{
		if (num[i] == true)
		{
			for (j = i + i; j < MAX_NUM; j = j + i)
			{
				num[j] = false;
			}
		}
	}
}

int main()
{
	arato();
	int n, t;

	int j, i;

	cin >> t;

	for (i = 0; i < t; i++)
	{
		cin >> n;
		for (j = n / 2; j > 1; j--)
		{
			if (num[j] == true && num[n - j] == true)
			{
				cout << j << " " << n - j << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}