#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define MAXNUM 2147483647

int T;
int n, m, k;

struct node
{
	int pos, cost, time;
	bool operator < (const node &p) const
	{
		if (this->time == p.time)
			return this->cost > p.cost;
		return
			this->time > p.time;
	}
};

int dp[101][10001];
vector<node> adj[101];


int dijkstra(int nodes, int money)
{
	for (int i = 1; i <= nodes; i++)
	{
		for (int j = 0; j <= money; j++)
		{
			dp[i][j] = MAXNUM;
		}
	}
	priority_queue<node> pq;

	pq.push({ 1 ,money,0 });
	dp[1][money] = 0;

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		int cost = tmp.cost;
		int dtime = tmp.time;
		int pos = tmp.pos;

		if (pos != 1 && dp[pos][cost] <= dtime)
			continue;

		dp[pos][cost] = dtime;

		if (pos == nodes)
		{
			break;
		}

		for (auto &next : adj[pos])
		{
			if (cost - next.cost >= 0 && dp[next.pos][cost - next.cost] > dp[pos][cost] + next.time)
			{
				pq.push({ next.pos, cost - next.cost, dp[pos][cost] + next.time });
			}
		}
	}

	int ans = MAXNUM;
	for (int i = 0; i <= money; i++)
	{
		ans = min(ans, dp[nodes][i]);
	}

	return ans;

	
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int u, v, w;

	cin >> T;

	while (T--)
	{
		cin >> n >> m >> k;

		while (k--)
		{
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u].push_back({ v, c, d });

		}

		int r = dijkstra(n, m);
		if (r < MAXNUM)
			cout << r << endl;
		else
			cout << "Poor KCM" << endl;

		for (int i = 0; i <= n; i++)
		{
			adj[i].clear();
		}
	}
	system("pause");
	return 0;
}
