#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

struct MakeOne
{
	int before;
	int cnt;
};

const int MAXNUM = 1000001;
MakeOne dp[MAXNUM];

void MakeDP(int num)
{
	dp[1].before = -1;
	dp[1].cnt = 0;
	for (int i = 2; i <= num; i++)
	{
		dp[i].cnt = dp[i - 1].cnt + 1;
		dp[i].before = i - 1;
		
		if (i % 2 == 0 && dp[i].cnt > dp[i / 2].cnt + 1)
		{
			dp[i].cnt = dp[i / 2].cnt + 1;
			dp[i].before = i / 2;
		}

		if (i % 3 == 0 && dp[i].cnt > dp[i / 3].cnt + 1)
		{
			dp[i].cnt = dp[i / 3].cnt + 1;
			dp[i].before = i / 3;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	MakeDP(n);

	cout << dp[n].cnt << '\n';

	int beforeNum = n;

	while (beforeNum > 0)
	{
		cout << beforeNum << ' ';
		beforeNum = dp[beforeNum].before;
	}

	return 0;
}