#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int su[1001] = { INT_MIN, };
int dp[1001] = { 0, };
int n, dpmax;

int main()
{

	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> su[i];
	}
	dpmax = 1;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (su[i] > su[j] && dp[i] <= dp[j])
			{
				dp[i] = dp[j] + 1;
				if (dp[i] > dpmax)
				{
					dpmax = dp[i];
				}
			}
			else if (j == 0 && dp[i] == 0)
			{
				dp[i] = 1;
			}
		}
	}

	cout << dpmax << endl;
	return 0;
}