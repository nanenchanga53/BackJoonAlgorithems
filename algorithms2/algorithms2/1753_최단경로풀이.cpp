#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cstdio>

using namespace std;

// �׷����� ���� ����Ʈ. (����� ���� ��ȣ, ���� ����ġ) ���� ��ƾ� �Ѵ�.
vector< pair<int, int>> adj[20001]; // 2���� �迭�� ����

vector<int> dijkstra(int src, int V, int E)
{
	// V��ŭ �迭�� INT_MAX�� �ʱ�ȭ
	vector<int> dist(V, INT_MAX);
	dist[src] = 0;

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, src));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		// ���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� �������� �����Ѵ�.
		if (dist[here] < cost)
			continue;

		// ������ �������� ��� �˻�.
		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;

			// �� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
				/*
				���⼭ -�� �ִ� ����?
				priority_queue STL�� �⺻������ ���� ū ���Ұ� ���� ������ ť�� ����
				���� �Ÿ��� ��ȣ�� �ٲ㼭 �Ÿ��� ���� �������� ���������� �ϱ� ����
				*/
			}
		}
	}

	return dist;
}

int main()
{
	// ����, ������ ���� �� ������
	int V, E, start;

	cin >> V >> E;
	cin >> start;

	V++; // ������ ������ 1���� �����ϸ� V++���ش�.

	for (int i = 0; i < E; i++)
	{
		int from, to, val;
		cin >> from >> to >> val;

		adj[from].push_back(make_pair(to, val));
	}

	vector<int> ans = dijkstra(start, V, E);

	for (int i = 1; i < V; i++)
		ans[i] == INT_MAX ? printf("INF\n") : printf("%d\n", ans[i]);

	system("pause");
	return 0;
}