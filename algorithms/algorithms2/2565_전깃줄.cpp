#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int x, y;
int beam[501];
int dp[501];
int ret;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		beam[x] = y;
	}

	ret = 0;

	for (int i = 1; i <= 500; i++)
	{
		if (beam[i] == 0) continue;

		dp[i] = 1;

		for (int j = 1; j < i; j++)
		{
			if (beam[j] < beam[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(ret, dp[i]);
	}
	cout << n - ret;
	return 0;
}