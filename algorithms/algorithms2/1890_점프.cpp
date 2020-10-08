#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
#define MAXNUM 100

long long ground[MAXNUM+2][MAXNUM+2];
long long dp[MAXNUM + 2][MAXNUM + 2];
int n;
long long cnt;

int main() 
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> ground[i][j];
		}
	}
	
	dp[1][1] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (ground[i][j] == 0)
			{
				continue;
			}

			if (j + ground[i][j] <= n)
			{
				dp[i][j + ground[i][j]] += dp[i][j];
			}

			if (i + ground[i][j] <= n)
			{
				dp[i + ground[i][j]][j] += dp[i][j];
			}
		}
	}

	if (ground[1][1] == 0)
		cout << 0 << endl;
	else
	{
		cout << dp[n][n] << endl;
	}

	system("pause");
	return 0;
}
