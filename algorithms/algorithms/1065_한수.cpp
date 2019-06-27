#include <stdio.h>
int main()
{
	int a[3];
	int han, n, k, i, t;

	scanf("%d", &n);

	if (n == 1000)
		n = 999;

	if (n < 100)
		han = n;
	else if (100 <= n && n <= 1000)
	{
		han = 99;

		for (i = 100; i <= n; i++)
		{
			t = i;
			for (k = 0; k < 3; k++)
			{
				a[k] = t % 10;
				t /= 10;
			}

			if ((a[0] - a[1]) == (a[1] - a[2]))
				han++;
		}
	}

	printf("%d", han);
	return 0;
}