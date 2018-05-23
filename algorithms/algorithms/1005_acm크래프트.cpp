#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int buildTime[1001] = { 0, };  //�� �ǹ� �Ǽ��ð� �Է�
int getTime[1001] = { 0, };    //�� �ǹ��� �������µ� �ɸ��� �� �ð�
int check[1001][2] = { 0 };    //[n][0] n�� �ǹ��� ����� ���� �� [n][1] n�� �ǹ��� Bfs�˻��� �湮�ߴ��� Ȯ��
vector<int> logic[1001];	   //[n] : n�� �ǹ��� ������ ����
queue<int> arr, bfsQue;	   //�������� queue,  bfs�������� �˻��� ���� queue
int T, n, k, x, y, w, d;

void arrange_bfs()
{
	int i, j;

	while (!bfsQue.empty())
	{
		i = bfsQue.front();
		bfsQue.pop();

		check[i][1] = 1;
		arr.push(i);
		for (j = 0; j < logic[i].size(); j++)
		{
			check[logic[i][j]][0]--;
			if (check[logic[i][j]][0] == 0 && check[logic[i][j]][1] == 0)
			{
				bfsQue.push(logic[i][j]);
			}
		}
	}
}

int find_time(int now)
{
	if (getTime[now] == 0)
		getTime[now] = buildTime[now];

	if (now == w)
		return getTime[now];

	for (int i = 0; i < logic[now].size(); i++)
	{
		if (getTime[logic[now][i]] < getTime[now] + buildTime[logic[now][i]])
		{
			getTime[logic[now][i]] = getTime[now] + buildTime[logic[now][i]];
		}
	}

	return 0;
}

int main()
{
	int i, p, j;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		memset(buildTime, 0, sizeof(buildTime));
		memset(getTime, 0, sizeof(getTime));
		memset(check, 0, sizeof(check));
		for (i = 0; i < 1000; i++)
			logic[i].clear();

		cin >> n >> k;
		for (i = 0; i < n; i++)
		{
			cin >> buildTime[i];
		}

		for (i = 0; i < k; i++)
		{
			cin >> x >> y;
			logic[x - 1].push_back(y - 1);
			check[y - 1][0]++;
		}
		cin >> w;
		w--;

		for (i = 0; i < n; i++)
		{
			if (check[i][0] == 0 && check[i][1] == 0)
			{
				check[i][1] = 1;
				bfsQue.push(i);
			}
		}

		arrange_bfs();

		int res = 0;
		while (!arr.empty())
		{
			res = find_time(arr.front());
			if (res != 0)
				break;
			arr.pop();
		}

		cout << res << endl;
	}

	system("pause");
	return 0;
}