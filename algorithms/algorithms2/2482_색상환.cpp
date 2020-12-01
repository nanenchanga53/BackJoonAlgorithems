#include<iostream>

using namespace std;

const int divNum = 1000000003;

int dp[1001][1001]; //[현재 고를 수 있는 색의 수][이때까지 고른 수]


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % divNum;
		}
	}

	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % divNum << '\n'; //n번째 색을 고른 경우와 안오른 경우를 합친다. 

	return 0;
}