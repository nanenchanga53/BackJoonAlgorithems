#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int su[1001] = { INT_MIN, };
pair<int, int> dp[1001] = { make_pair(0,0), };
int n, dpmax;

int main()
{

	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> su[i];
	}
	dp[0].first = 0;
	dp[1].first = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (su[i] > su[j] && dp[i].first <= dp[j].first)
			{
				dp[i].first = dp[j].first + 1;
			}
			else if (j == 0 && dp[i].first == 0)
			{
				dp[i].first = 1;
			}
		}
	}

	dp[n].second = 0;
	dp[n].second = 0;

	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (su[i] > su[j] && dp[i].second <= dp[j].second)
			{
				dp[i].second = dp[j].second + 1;
			}
			else if (j == 0 && dp[i].second == 0)
			{
				dp[i].second = 1;
			}
		}
	}

	dpmax = 1;
	for (int i = 1; i <= n; i++)
	{
		if (n == 1) break;
		if (dp[i].first + dp[i].second > dpmax)
		{
			dpmax = dp[i].first + dp[i].second;
		}
	}

	cout << dpmax << endl;
	return 0;
}