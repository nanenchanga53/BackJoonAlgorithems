#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int m, n, time;

int way[102][102] = { 0, };
bool flag[102] = { 0, };
int pointX[5] = { -1,0,1,0 };
int pointY[5] = { 0,-1,0,1 };
int nowLen;

void dfs(int now)
{
	for (int i = 1; i <= n; i++)
	{
		if ((way[now][i] == 1) && (flag[i] == false))
		{
			flag[i] = true;
			dfs(i);
		}
	}
}

int main()
{
	int x, y;

	cin >> n;
	cin >> m;
	flag[1] = true;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		way[x][y] = 1;
		way[y][x] = 1;
	}

	dfs(1);

	int cnt=0;

	for (int i = 1; i <= n; i++)
	{
		if (flag[i] == 1)
		{
			cnt++;
		}
	}

	cout << cnt - 1;

	system("pause");
	return 0;
}
