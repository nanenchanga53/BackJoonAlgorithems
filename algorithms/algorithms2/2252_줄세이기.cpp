#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int n, m;
vector<int> smaller[32001];
int taller[32001];
queue<int> que;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(taller, 0, sizeof(taller));

	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		taller[b]++;
		smaller[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (taller[i] == 0)
			que.push(i);
	}
	while (!que.empty())
	{
		int temp = que.front();
		que.pop();
		cout << temp << " ";
		for (int i = 0; i < smaller[temp].size(); i++)
		{
			taller[smaller[temp][i]]--;
			if (taller[smaller[temp][i]] == 0)
			{
				que.push(smaller[temp][i]);
			}
		}

	}
	system("pause");
	return 0;
}
