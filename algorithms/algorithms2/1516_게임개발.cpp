#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int n, m;
int time[501]; //건물자체 생산시간
int indegree[501]; //진입차수
int ans[501]; // 최소생산시간
vector<int> pre[501]; //인접리스트

void bfs()
{
	queue<int> que;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			que.push(i);
			ans[i] = time[i];
		}
	}

	while (!que.empty())
	{
		int nowEdge = que.front();
		que.pop();

		for (int i = 0; i < pre[nowEdge].size(); i++)
		{
			int edge = pre[nowEdge][i];

			ans[edge] = max(ans[edge], ans[nowEdge] + time[edge]);

			if (--indegree[edge] == 0)
			{
				que.push(edge);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int lastStructure;
	memset(time, 0, sizeof(time));

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> time[i];
		while (cin >> lastStructure, lastStructure != -1)
		{
			pre[lastStructure].push_back(i);
			indegree[i]++;
		}
	}


	//for (int i = 1; i <= n; i++)
	//{
	//	cout << indegree[i] << endl;
	//}

	bfs();

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << endl;
	}

	system("pause");
	return 0;
}
