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

	for (int i = big + 1; i <= n; i++)
	{
		if (usedNum[i] == 0)
		{
			usedNum[i] = 1;
			solve[cnt] = i;
			BackTracking(cnt + 1, i);
			usedNum[i] = 0;
			solve[cnt] = 0;
		}
	}
}

int main()
{

	scanf("%d %d", &n, &m);

	BackTracking(0, 0);

	return 0;
}