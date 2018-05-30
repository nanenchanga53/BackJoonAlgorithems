#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n;
int maxDP[3] = { 0, }, minDP[3] = { 0, };
int lastMaxDP[3] = { 0, }, lastMinDP[3] = { 0, };

inline int max(int a, int b, int c) 
{ 
	return max(a, max(b, c)); 
}

inline int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int l, m, r;

	for (int i = 1; i <= n; i++)
	{
		cin >> l >> m >> r;

		for (int i = 0; i < 3; i++)
		{
			lastMaxDP[i] = maxDP[i];
			lastMinDP[i] = minDP[i];
		}

		maxDP[0] = max(lastMaxDP[0], lastMaxDP[1]) + l;
		maxDP[1] = max(lastMaxDP[0], lastMaxDP[1], lastMaxDP[2]) + m;
		maxDP[2] = max(lastMaxDP[1], lastMaxDP[2]) + r;

		minDP[0] = min(lastMinDP[0], lastMinDP[1]) + l;
		minDP[1] = min(lastMinDP[0], lastMinDP[1], lastMinDP[2]) + m;
		minDP[2] = min(lastMinDP[1], lastMinDP[2]) + r;
	}

	int maxNum, minNum;

	maxNum = max(maxDP[0], maxDP[1], maxDP[2]);
	minNum = min(minDP[0], minDP[1], minDP[2]);

	cout << maxNum << ' ' << minNum << endl;
	

	system("pause");

	return 0;
}
