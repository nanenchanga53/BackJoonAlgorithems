#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXNUM = 100001;

int n,r,q;
vector<vector<int>> node;
int dp[MAXNUM];
bool visit[MAXNUM];

int dfs(int now)
{
	//재방문은 하지 않는다
	if (visit[now] == true) return dp[now];
	visit[now] = true;

	//현재 노드와 인접한 곳을 전부 돈다
	for (auto next : node[now])
	{
		if (visit[next] == true) continue;
		dp[now] = dp[now] + dfs(next);
	}
	return dp[now];

}


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int u=0, v=0;

	cin >> n >> r >> q;

	for (int i = 1; i <= n; i++)
		dp[i] = 1;

	node.resize(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	dfs(r);
	for (int i = 0; i < q; i++)
	{
		cin >> u;
		cout << dp[u] << '\n';
	}

	return 0;

}