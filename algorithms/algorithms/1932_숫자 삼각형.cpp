#include<iostream>
#include<algorithm>
using namespace std;

int n;
int triangle[501][501] = { 0, };

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];

	for (int i = 1; i < n; i++)
	{
		triangle[i][0] += triangle[i - 1][0];
		triangle[i][i] += triangle[i - 1][i - 1];
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			triangle[i][j] = max(triangle[i - 1][j - 1] + triangle[i][j], triangle[i - 1][j] + triangle[i][j]);
		}
	}

	int max_num = 0;

	for (int i = 0; i < n; i++)
		max_num = max(max_num, triangle[n - 1][i]);

	cout << max_num << endl;

	system("pause");
	return 0;
}