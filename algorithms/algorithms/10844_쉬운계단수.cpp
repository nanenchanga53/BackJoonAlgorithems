#include<iostream>
using namespace std;
#define MOD 1000000000

int main()
{
	int n;
	int i, j;
	unsigned int stair[101][11] = { 0, };
	unsigned int sum;
	sum = 0;
	cin >> n;

	for (i = 1; i <= 9; i++)
	{
		stair[1][i] = 1;
	}

	for (i = 2; i <= n; i++)
	{
		stair[i][0] = stair[i - 1][1];

		for (j = 1; j <= 9; j++)
		{
			stair[i][j] = (stair[i - 1][j - 1] + stair[i - 1][j + 1]) % MOD;
		}
	}

	for (i = 0; i <= 9; i++)
		sum = (sum + stair[n][i]) % MOD;

	cout << sum << endl;

	system("pause");
	return 0;
}