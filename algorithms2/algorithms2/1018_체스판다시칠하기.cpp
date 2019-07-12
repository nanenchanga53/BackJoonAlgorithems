#include<iostream>
#include<algorithm>
using namespace std;

int n, m, res;
bool chess[51][51];
char c;

bool p1[8][8], p2[8][8];

int cmp(int x, int y)
{
	int ret1 = 0, ret2 = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (chess[i + x][j + y] != p1[i][j]) ret1++;
			if (chess[i + x][j + y] != p2[i][j]) ret2++;
		}
	}
	return min(ret1, ret2);
}

int main()
{
	res = 65;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				p1[i][j] = true;
				p2[i][j] = false;
			}
			else
			{
				p1[i][j] = false;
				p2[i][j] = true;
			}
		}
	}

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			if (c == 'W') chess[i][j] = true;
			else chess[i][j] = false;
		}
	}

	for (int i = 7; i < n; i++)
	{
		for (int j = 7; j < m; j++)
		{
			res = min(res, cmp(i - 7, j - 7));
		}
	}

	cout << res << endl;

	return 0;
}