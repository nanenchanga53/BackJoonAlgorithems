#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int n; // ������ ��
int house[3][1001];
int dp[3][1001];

const int MAXNUM = 1000001;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> house[j][i]; // ���� �� ���� ���ٿ� �־�� �Ǵ� [i][j]�� �ƴϴ�
		}
	}

	int res = MAXNUM;

	for (int i = 0; i < 3; i++)
	{
		dp[0][0] = MAXNUM;
		dp[1][0] = MAXNUM;
		dp[2][0] = MAXNUM;
		dp[i][0] = house[i][0];

		for (int j = 1; j < n; j++)
		{
			dp[0][j] = min(dp[1][j - 1], dp[2][j - 1]) + house[0][j];
			dp[1][j] = min(dp[2][j - 1], dp[0][j - 1]) + house[1][j];
			dp[2][j] = min(dp[0][j - 1], dp[1][j - 1]) + house[2][j];
		}

		for (int j = 0; j < 3; j++)
		{
			if (j == i) continue;
			res = min(res, dp[j][n - 1]);
		}
	}
	cout << res << '\n';
	return 0;
}