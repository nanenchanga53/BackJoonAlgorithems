#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<functional>

using namespace std;

int n, m;
vector<int> easy[32001];
int indegree[32001];
priority_queue< int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(indegree, 0, sizeof(indegree));

	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		indegree[b]++;
		easy[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			pq.push(i);
	}
	while (!pq.empty())
	{
		int temp = pq.top();
		pq.pop();
		cout << temp << " ";
		for (int i = 0; i < easy[temp].size(); i++)
		{
			indegree[easy[temp][i]]--;
			if (indegree[easy[temp][i]] == 0)
			{
				pq.push(easy[temp][i]);
			}
		}

	}
	system("pause");
	return 0;
}