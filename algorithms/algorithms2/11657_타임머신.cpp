#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<functional>

using namespace std;

#define MAXNUM 2147483647

int n, m, w, T;
long long dist[501]; //범위가 넘어가서 출력초가 날 수 있으므로 Int론 안됨
vector<pair<int, int>> adj[501];

bool velmanpord()
{
	bool minusCycle = false;
	fill(dist + 1, dist + n + 1, MAXNUM);
	dist[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (auto &next : adj[j]) //minus cycle
			{
				if (dist[j] != MAXNUM && dist[next.first] > dist[j] + next.second)
				{
					dist[next.first] = dist[j] + next.second;
					if (i == n)
					{
						minusCycle = true;
					}
				}
			}
		}
	}
	if (minusCycle)
		return true;
	else
		return false;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		adj[s].push_back(make_pair(e, t));
	}
	bool minCycle = velmanpord();


	if (minCycle)
	{
		cout << "-1" << '\n';
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			int print;
			print = dist[i] != MAXNUM ? dist[i] : -1;
			cout << print << '\n';
		}
	}

	return 0;
}