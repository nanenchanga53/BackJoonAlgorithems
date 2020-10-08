#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int m, n, h, time;

int tomato[102][102][102] = { 0, };

struct tomatoPoint
{
	int x;
	int y;
	int z;
};

queue<tomatoPoint> qu;

void bfs(int x, int y, int z)
{
	int xm, xp, ym, yp, zm, zp;
	xm = x - 1;
	xp = x + 1;
	ym = y - 1;
	yp = y + 1;
	zm = z - 1;
	zp = z + 1;

	if (tomato[z][y][xm] == 0 && xm > 0)
	{
		tomato[z][y][xm] = tomato[z][y][x] + 1;
		qu.push({ xm,y,z });
	}

	if (tomato[z][y][xp] == 0 && xp <= m)
	{
		tomato[z][y][xp] = tomato[z][y][x] + 1;
		qu.push({ xp, y,z });
	}

	if (tomato[z][ym][x] == 0 && ym > 0)
	{
		tomato[z][ym][x] = tomato[z][y][x] + 1;
		qu.push({ x,ym,z });
	}

	if (tomato[z][yp][x] == 0 && yp <= n)
	{
		tomato[z][yp][x] = tomato[z][y][x] + 1;
		qu.push({ x, yp, z });
	}
	
	if (tomato[zm][y][x] == 0 && zm > 0)
	{
		tomato[zm][y][x] = tomato[z][y][x] + 1;
		qu.push({ x,y,zm });
	}

	if (tomato[zp][y][x] == 0 && zp <= h)
	{
		tomato[zp][y][x] = tomato[z][y][x] + 1;
		qu.push({ x, y, zp });
	}
}

int main()
{
	cin >> m >> n >> h;

	time = 1;
	for (int k = 1; k <= h; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cin >> tomato[k][i][j];
				if (tomato[k][i][j] == 1)
					qu.push({j,i,k});

			}
		}
	}

	tomatoPoint t;

	while (!qu.empty())
	{
		t = qu.front();
		qu.pop();

		bfs(t.x, t.y, t.z);
	}

	bool done = true;

	for (int k = 1; k <= h; k++)
	{

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (tomato[k][i][j] == 0)
				{
					done = false;
					break;
				}

				if (time < tomato[k][i][j])
					time = tomato[k][i][j];
			}
			if (done == false)
				break;
		}
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
