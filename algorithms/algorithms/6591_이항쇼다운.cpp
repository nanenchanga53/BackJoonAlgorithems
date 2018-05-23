#pragma warning(disable:4996)
#include<iostream>
using namespace std;
#define MAX_NUM 2147483648

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int find_coe(int n, int k)
{
	long long ans = 1;
	long long bns = 1;
	for (int i = 1; i <= k; i++)
	{
		ans *= (n - i + 1);
		bns *= i;
		if (ans % bns == 0)
		{
			ans /= bns;
			bns = 1;
		}
	}
	return (int)ans;
}

int main()
{
	int n, k;

	while (1)
	{
		scanf("%d %d", &n, &k);

		if (n == 0 && k == 0)
			break;

		if (k < 0 || k > n)
			printf("0\n");
		else
			printf("%d\n", find_coe(n, min(k, n - k)));
	}
	system("pause");

	return 0;
}