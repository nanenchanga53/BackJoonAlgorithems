#include<iostream>
#include<cmath>
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
	int n, m;

	int i, j;
	cin >> m >> n;

	for (int i = m; i <= n; i++)
		if (num[i] == true)
			cout << i << endl;

	system("pause");
	return 0;
}