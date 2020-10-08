#include<iostream>
using namespace std;
int coin[101] = { 0, };
//int canMake[101][10001] = { 0, };
int canMake[10001] = { 0, };
int main()
{
	int n, k;
	int i, j;
	

	cin >> n >> k;

	for (i = 1; i <= n; i++)
	{
		cin >> coin[i];
		//canMake[i][coin[i]] = 1;
	}

	for (i = 1; i <= n; i++)
	{
		if (coin[i] > 10000)
			continue;
		canMake[coin[i]] += 1;
		for (j = coin[i] + 1; j <= k; j++)
		{
			//if (j < coin[i])
			//{
				//canMake[i][j] += canMake[i - 1][j];
			//}
			//else
			//{
				//canMake[i][j] += canMake[i - 1][j] + canMake[i][j - coin[i]];
			//}

			canMake[j] += canMake[j - coin[i]];
		}
	}

	//cout << canMake[n][k] << endl;
	cout << canMake[k] << endl;
	system("pause");
	return 0;
}