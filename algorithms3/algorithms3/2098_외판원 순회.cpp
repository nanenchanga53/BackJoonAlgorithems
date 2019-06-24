#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXNUM 16000000

using namespace std;

int n;
int dp[17][1 << 16]; //dp[current][visited] 현재 위치가 current이고 방문했던 도시들이 visited일 때, 부분 경로(집합)최솟값 
int w[17][17];

int getShortestLoot(int current, int visited)
{
	if (visited == (1 << n) - 1)
		return w[current][1];

	if (dp[current][visited] >= 0)
		return dp[current][visited];

	int ret = MAXNUM;

	for (int i = 1; i <= n; i++)
	{
		int next = i;
		if ((visited & (1 << (next - 1))) != 0)
			continue;

		if (w[current][next] == 0)
			continue;

		int temp = w[current][next] + getShortestLoot(next, visited + (1 << (next - 1)));
		ret = min(ret, temp);
	}

	return dp[current][visited] = ret;


}

int main()
{
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> w[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	int start = 1;
	cout << getShortestLoot(start, 1);

	system("pause");
	return 0;
}