#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;


int T;
int n, m, k;
const int MAXNUM = 1000000007;

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

int dp[101][10001] = { 0, };
vector<node> adj[101];


int dijkstra()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			dp[i][j] = MAXNUM;
		}
	}
	priority_queue<node> pq;

	pq.push({ 1 ,0, 0 });
	dp[1][0] = 0;

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();
		
		int pos = tmp.pos;
		int cost = tmp.cost;
		int dtime = tmp.time;

		if (dp[pos][cost] < dtime)
			continue;

		for (auto &next : adj[pos])
		{
			if (cost + next.cost > m) continue;
			if (dp[next.pos][cost + next.cost] > dtime + next.time)
			{
				pq.push({ next.pos, cost + next.cost, dp[pos][cost] + next.time });
				dp[next.pos][cost + next.cost] = dtime + next.time;
			}
		}
	}

	int ans = MAXNUM;
	for (int i = 1; i <= m; i++)
	{
		ans = min(ans, dp[n][i]);
	}

	return ans;

	
	
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> T;

	int u, v, c, d;

	while (T--)
	{
		cin >> n >> m >> k;

		while (k--)
		{
			
			cin >> u >> v >> c >> d;
			adj[u].push_back({ v, c, d });

		}

		int r = dijkstra();
		if (r == MAXNUM)
			cout << "Poor KCM" << '\n';
		else
			cout << r << '\n';

		for (int i = 0; i <= n; i++)
		{
			adj[i].clear();
		}
	}

	return 0;
}
