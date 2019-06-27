#include<iostream>
#include<cstring>
using namespace std;

char star[6562][6562];

void makeStar(int depth, int w, int h)
{
	if (depth == 1)
	{
		star[w][h] = '*';
		return;
	}
	int next = depth / 3;
	for (int i = 0, x = w; i < 3; i++, x += next)
	{
		for (int j = 0, y = h; j < 3; j++, y += next)
		{
			if (i == 1 && j == 1) continue;
			makeStar(depth / 3, x, y);

		}
	}
}

int main()
{
	int n;

	cin >> n;

	memset(star, ' ', sizeof(star));

	makeStar(n, 1, 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << star[i][j];
		cout << endl;
	}

	return 0;
}