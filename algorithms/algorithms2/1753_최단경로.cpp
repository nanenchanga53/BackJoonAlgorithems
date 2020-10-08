#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int V, E, K;
int dist[20001] = { 0 };
struct line_info
{
	int now;
	int last;
	int value;
};

bool operator < (line_info t, line_info u)
{
	return t.value > u.value;
}

vector<vector<pair<int,int>>> graph;
priority_queue<line_info> heap;

int readInt()
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch - '0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


int main()
{
	int u, v, w;

	V = readInt();
	E = readInt();
	K = readInt();

	graph.resize(V+1);

	for (int i = 0; i < E; i++)
	{
		pair<int, int> t;
		u = readInt();
		v = readInt();
		w = readInt();
		t.first = v;
		t.second = w;
		graph[u].push_back(t);
	}

	line_info info;
	info.now = K;
	info.last = K;
	info.value = 0;
	heap.push(info);

	for (int i = 1; i <= V; i++)
		dist[i] = 20001;
	
	dist[K] = 0;

	int t;

	while (!heap.empty())
	{
		line_info top_info;
		top_info = heap.top();
		heap.pop();

		if (dist[top_info.now] < top_info.value)
		{
			continue;
		}

		for (int i = 0; i < graph[top_info.now].size(); i++)
		{
			int there = graph[top_info.now][i].first;
			int nextDist = dist[top_info.now] + graph[top_info.now][i].second;

			if(dist[there] > nextDist)
			//if (dist[graph[top_info.now][i].first] > graph[top_info.now][i].second)
			{
				dist[there] = nextDist;
				info.last = top_info.now;
				info.now = graph[top_info.now][i].first;
				info.value = graph[top_info.now][i].second;
				heap.push(info);
			}

		}
		
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] < 20001)
			cout << dist[i] << endl;
		else
			cout << "INF" << endl;
	}
	system("pause");
	return 0;
}
