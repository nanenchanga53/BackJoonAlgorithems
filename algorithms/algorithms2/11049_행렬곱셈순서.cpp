#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int n;
int arr[501];
int dp[501][501];

int main()
{

	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i - 1] >> arr[i];
	}

	for (int i = 1; i < n; i++)
	{
		dp[i][i + 1] = arr[i - 1] * arr[i] * arr[i + 1];
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= n - i + 1; j++)
		{
			int sum = 0;
			for (int k = j; k < j + i - 1; k++)
			{
				int res;
				res = dp[j][k] + dp[k + 1][i + j - 1] + arr[j - 1] * arr[k] * arr[j + i - 1];
				if (sum == 0 || sum > res)
				{
					sum = res;
				}
			}
			dp[j][j + i - 1] = sum;
		}
	}
	cout << dp[1][n] << endl;

	return 0;
}