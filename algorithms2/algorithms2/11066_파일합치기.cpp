#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int T,n;
	int k,i,j;
	int novel[501] = { 0, };
	int minSum[501][501] = { 0, };

	cin >> T;

	while (T--)
	{
		cin >> n;
		memset(novel, 0, sizeof(novel));
		memset(minSum, 0, sizeof(minSum));
		for (i = 1; i <= n; i++)
		{
			cin >> novel[i];
			novel[i] += novel[i - 1];
		}

		for (i = 2; i <= n; i++)
		{
			for (j = i; --j;)
			{
				minSum[j][i] = 2e9;
				for (k = j; k <= i; k++)
				{
					minSum[j][i] = min(minSum[j][i], minSum[j][k] + minSum[k + 1][i]);
				}
					minSum[j][i] += novel[i] - novel[j - 1];
				
			}
		}
		

		cout << minSum[1][n] << endl;
	}
	system("pause");
	return 0;
}

