#include<iostream>
#include<cstring>
using namespace std;

char star[3080][10080];

void makeStar(int n, int x, int y)
{
	if (n == 3)
	{
		star[x][y] = '*';
		star[x + 1][y - 1] = star[x + 1][y + 1] = '*';
		for (int i = 0; i < 5; i++)
		{
			star[x + 2][y - 2 + i] = '*';
		}
		return;
		
	}
	else
	{
		int ny1 = y - n / 2;
		int ny2 = y + n / 2;
		int nx = x + n / 2;

		makeStar(n / 2, x, y);
		makeStar(n / 2, nx, ny1);
		makeStar(n / 2, nx, ny2);
	}
}

int main()
{
	int n;

	cin >> n;

	memset(star, ' ', sizeof(star));

	makeStar(n, 0, n-1);

	for (int i = 0; i < n; i++) {
		star[i][2 * n] = NULL;
	}
	star[n - 1][2 * n - 1] = NULL;


	for (int i = 0; i < n; i++)
	{
		puts(star[i]);
	}

	system("pause");
	return 0;
}