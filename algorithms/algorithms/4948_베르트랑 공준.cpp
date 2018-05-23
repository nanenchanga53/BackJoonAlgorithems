#include<iostream>
#include<cstring>
using namespace std;

#define MAX_NUM 1000001

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
	int n;

	int i;
	int cnt;

	while (1)
	{
		cin >> n;
		if (n == 0)
			return 0;
		cnt = 0;

		for (int i = n + 1; i <= n * 2; i++)
			if (num[i] == true)
				cnt++;

		cout << cnt << endl;
	}
	return 0;
}