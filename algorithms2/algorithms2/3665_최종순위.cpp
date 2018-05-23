#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int n, m,T;
int lastRank[501] = {};
int graph[501][501] = { 0, };
int in[501];
int result[501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	cin >> T;
	while (T--)
	{
		int f = 0;
		memset(lastRank, 0, sizeof(lastRank));
		memset(graph, 0, sizeof(graph));
		memset(in, 0, sizeof(in));
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> lastRank[i];
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				graph[lastRank[j]][lastRank[i]] = 1;
				in[lastRank[i]]++;

			}
		}

		cin >> m;
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			if (graph[x][y])
			{
				in[y]--;
				in[x]++;
			}
			else
			{
				in[y]++;
				in[x]--;
			}
			swap(graph[x][y], graph[y][x]);
		}

		queue<int> qu;
		for (int i = 1; i <= n; i++)
		{
			if (in[i] == 1)
			{
				qu.push(i);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (qu.empty())
			{
				f = 1;
				break;
			}
			else if (qu.size() > 1)
			{
				f = 2;
				break;
			}
			else
			{
				int now = qu.front();
				result[i] = now;
				qu.pop();
				for (int j = 1; j <= n; j++)
				{
					if (graph[now][j])
					{
						in[j]--;
						if (in[j] == 1)
						{
							qu.push(j);
						}
					}
				}
			}
		}

		if (f == 1)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else if (f == 2)
		{
			cout << "?" << endl;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				cout << result[i] << " ";
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;

}
