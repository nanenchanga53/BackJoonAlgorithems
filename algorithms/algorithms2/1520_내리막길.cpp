#include<iostream>
using namespace std;

const int MAX_M = 501;
const int MAX_N = 501;
int map[MAX_M][MAX_N];
int m, n;

int pY[4] = { -1, 1, 0, 0 };
int pX[4] = { 0, 0, -1, 1 };
int cache[MAX_M][MAX_N];

int dp(int y, int x);

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> map[i][j];
			cache[i][j] = -1;
		}
	}

	cout << dp(m, n) << endl;
	system("pause");
	return 0;
}

int dp(int y, int x)
{
	if (y == 1 && x == 1)
		return 1;

	int& ret = cache[y][x];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 4; ++i) {
		int prevY = y + pY[i];
		int prevX = x + pX[i];

		if (1 > prevY || prevY > m || 1 > prevX || prevX > n)
			continue;

		if (map[prevY][prevX] <= map[y][x])
			continue;

		ret += dp(prevY, prevX);
	}
	
	return ret;
}