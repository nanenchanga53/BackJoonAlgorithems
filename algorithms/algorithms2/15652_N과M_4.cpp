#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

int usedNum[10] = { 0, };
int solve[10] = { 0, };
int n, m;

void BackTracking(int cnt, int big)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++) printf("%d ", solve[i]);
		printf("\n");
		return;
	}

	for (int i = big; i <= n; i++)
	{
		solve[cnt] = i;
		BackTracking(cnt + 1, i);
		solve[cnt] = 0;
	}
}

int main()
{

	scanf("%d %d", &n, &m);

	BackTracking(0, 1);

	return 0;
}