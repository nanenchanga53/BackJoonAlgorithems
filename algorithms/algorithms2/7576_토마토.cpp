#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int m, n,time;

int tomato[1002][1002] = { 0, };
queue<pair<int,int>> qu;

void bfs(int x, int y)
{
	int xm, xp, ym, yp;
	xm = x - 1;
	xp = x + 1;
	ym = y - 1;
	yp = y + 1;
	
	if (tomato[xm][y] == 0 && xm > 0)
	{
		tomato[xm][y] = tomato[x][y] + 1;
		qu.push({ xm,y });
	}

	if (tomato[xp][y] == 0 && xp <= n)
	{
		tomato[xp][y] = tomato[x][y] + 1;
		qu.push({ xp,y });
	}

	if (tomato[x][ym] == 0 && ym > 0)
	{
		tomato[x][ym] = tomato[x][y] + 1;
		qu.push({ x,ym });
	}

	if (tomato[x][yp] == 0 && yp <= m)
	{
		tomato[x][yp] = tomato[x][y] + 1;
		qu.push({ x,yp });
	}
}

int main()
{
	cin >> m >> n;

	time = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> tomato[i][j];
			if(tomato[i][j] == 1)
				qu.push({ i,j });
			
		}
	}

	pair<int, int> t;

	while (!qu.empty())
	{
		t = qu.front();
		qu.pop();

		bfs(t.first, t.second);
	}

	bool done = true;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (tomato[i][j] == 0)
			{
				done = false;
				break;
			}

			if (time < tomato[i][j])
				time = tomato[i][j];
		}
		if (done == false)
			break;
	}

	if (done)
	{
		time--;
		cout << time;
	}
	else
	{
		cout << -1;
	}


	system("pause");
	return 0;
}
