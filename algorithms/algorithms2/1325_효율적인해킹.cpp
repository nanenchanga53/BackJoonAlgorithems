#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int n, m;
int maxNum = 0;
int sizes = 0;
vector<int> trust[10001];
int trustCnt[10001];
queue<int> que;


void bfs()
{
	
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		int visit[100001] = { 0 };

		que.push(i);
		visit[i] = 1;
		cnt++;

		while (!que.empty())
		{
			int now = que.front();
			que.pop();

			for (int j = 0; j < trust[now].size(); j++)
			{
				int temp = trust[now][j];

				if (visit[temp] == 0)
				{
					visit[temp] = 1;
					que.push(temp);
					cnt++;
				}
			}
		}

		if (maxNum < cnt)
		{
			sizes = 0;
			maxNum = cnt;
			trustCnt[sizes++] = i;

		}
		else if (maxNum == cnt)
		{
			trustCnt[sizes++] = i;
		}
	}
}

int main()
{
	int start, end;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;


	while (m--)
	{
		cin >> end >> start;
		trust[start].push_back(end);
	}

	bfs();

	for (int i = 0; i < sizes; i++)
	{
		cout << trustCnt[i] << endl;
	}

	system("pause");
	return 0;
	
}
