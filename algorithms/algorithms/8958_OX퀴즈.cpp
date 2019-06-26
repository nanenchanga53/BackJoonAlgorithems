#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char k[81];
	int n, len, sum, cnt;
	scanf("%d\n", &n);
	cin.clear();

	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		sum = 0;
		cin.getline(k, 80);
		len = strlen(k);
		for (int j = 0; j <= len; j++)
		{
			if (k[j] == 'X')
			{
				cnt = 0;
			}
			else if (k[j] == 'O')
			{
				cnt++;
				sum += cnt;
			}
		}
		cout << sum << endl;
	}
	return 0;
}