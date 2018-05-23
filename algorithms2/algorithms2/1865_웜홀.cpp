#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<functional>

using namespace std;

#define MAXNUM 2147483647

int n, m,w,T;
int dist[501];
vector<pair<int, int>> adj[501];
int mincycleV;
bool minAndCycle = false;
bool visited[501];

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
						mincycleV = j;
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

void bfs(int now)
{
	if (now == 1)
	{
		minAndCycle = true;
		return;
	}

	for (auto &next : adj[now])
	{
		if (visited[next.first] == false)
		{
			visited[next.first] = true;
			bfs(next.first);
			visited[next.first] = false;
		}
		if (minAndCycle)
			return;
	}

	return;
}

int main() //정확한 문제의 조건이 갈리는 문제 예전에는 음수사이클만 있으면 정답이었던것
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> w;
		for (int i = 1; i <= m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(e, t));
			adj[e].push_back(make_pair(s, t));
		}

		for (int i = 1; i <= w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(e, -t));
		}
		bool minCycle = velmanpord();


		if (minCycle)
		{
			bfs(mincycleV);
			if(minAndCycle)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	system("pause");
	return 0;
}