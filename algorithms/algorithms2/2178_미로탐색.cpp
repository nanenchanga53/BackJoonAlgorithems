#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int m, n, time;

int way[102][102] = { 0, };
int pointX[5] = { -1,0,1,0 };
int pointY[5] = { 0,-1,0,1 };
int nowLen;
queue<pair<int, int>> qu;

void bfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (way[x + pointX[i]][y + pointY[i]] == 1)
		{
			way[x + pointX[i]][y + pointY[i]] = nowLen;
			qu.push({ x + pointX[i], y + pointY[i] });
		}
	}

}

int main()
{
	nowLen = 2;
	cin >> n >> m;
	cin.get();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			way[i][j] = cin.get() - '0';
		}
		cin.get();
	}

	qu.push({ 1, 1 });


	pair<int, int> st;

	int lenCnt = 0;
	lenCnt = 1;
	while (qu.empty() == false)
	{
		st = qu.front();
		qu.pop();
		lenCnt--;
		bfs(st.first, st.second);

		if (lenCnt == 0)
		{
			lenCnt = qu.size();
			nowLen++;
		}
	}

	cout << way[n][m] << endl;
	system("pause");
	return 0;
}
