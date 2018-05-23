#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int price[1001][4] = { 0, };
int sum[1001][4] = { 0, };

int find_min(int roof, int color)
{
	int &rec = sum[roof][color];

	if (roof > n)
		return 0;

	if (rec != 0)
		return rec;

	rec = 2147483647;

	for (int i = 0; i < 3; i++)
	{
		if (color != i)
			rec = min(rec, find_min(roof + 1, i) + price[roof][i]);
	}

	return rec;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			cin >> price[i][j];

	cout << find_min(0, -1) << endl;

	system("pause");
	return 0;
}