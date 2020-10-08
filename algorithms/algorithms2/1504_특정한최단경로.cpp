#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<functional>

using namespace std;

#define MAXNUM 2147483647

struct node {
	int first;
	int second;
};

bool operator<(node a, node b) {
	return a.second > b.second;
}

int n, e;
int dist[801];
vector<pair<int, int>> adj[801];
priority_queue<node> pq,testpq;
int mustVertex1, mustVertex2;
int oneToV1, oneToV2, V1ToN, V2ToN, V1ToV2;

void dijkstra(int startNode)
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = MAXNUM;
	}
	dist[startNode] = 0;

	pq.push({ startNode, 0 });
	while (!pq.empty())
	{
		int cost = pq.top().second;
		int now = pq.top().first;
		pq.pop();
		
		if (dist[now] < cost)
			continue;

		for(pair<int, int> next : adj[now])
		{
			if (dist[next.first] > next.second + cost)
			{
				pq.push({ next.first, next.second + cost });
				dist[next.first] = next.second + cost;
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> e;

	while (e--)
	{
		int a, b, c;//정점,정점,크기
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	cin >> mustVertex1 >> mustVertex2;

	dijkstra(1);

	oneToV1 = dist[mustVertex1];
	oneToV2 = dist[mustVertex2];

	if (oneToV1 >= MAXNUM && oneToV2 >= MAXNUM)
	{
		cout << -1 << endl;
		return 0;
	}
	
	dijkstra(n);

	V1ToN = dist[mustVertex1];
	V2ToN = dist[mustVertex2];

	if (V1ToN >= MAXNUM && V2ToN >= MAXNUM)
	{
		cout << -1 << endl;
		return 0;
	}

	dijkstra(mustVertex1);

	V1ToV2 = dist[mustVertex2];

	if (V1ToN >= MAXNUM && V1ToV2 >= MAXNUM)
	{
		cout << -1 << endl;
		return 0;
	}

	int root1 = -1;
	int root2 = -1;
	if (!(oneToV1 >= MAXNUM || V1ToV2 >= MAXNUM || V2ToN >= MAXNUM))
	{
		root1 = oneToV1 + V1ToV2 + V2ToN;
	}
	if (!(oneToV2 >= MAXNUM || V1ToV2 >= MAXNUM || V1ToN >= MAXNUM))
	{
		root2 = oneToV2 + V1ToV2 + V1ToN;
	}

	if (root1 == -1 && root2 == -1)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << min(root1, root2) << endl;
	}

	system("pause");
	return 0;
}