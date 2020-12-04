#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int su[1001] = { INT_MIN, };
int dp[1001] = { 0, };
vector<int> list[1001];
vector<int> ans;
int n;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> su[i];
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		list[i].push_back(su[i]);
		for (int j = 1; j < i; j++)
		{
			if (su[i] > su[j] && dp[i] < dp[j] + 1)
			{
				
				list[i].clear();
				list[i] = list[j];
				list[i].push_back(su[i]);
				dp[i] = dp[j] + 1;
			}
		}
		if (ans.size() < list[i].size())
			ans = list[i];
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}


	return 0;
}