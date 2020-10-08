#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int mapA[101][101] = { 0, };
int mapB[101][101] = { 0, };
int mapS[101][101] = { 0, };

int n, m, k;


int main()
{
	int i, j;

	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> mapA[i][j];
		}
	}
	cin >> m >> k;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < k; j++)
		{
			cin >> mapB[i][j];
		}
	}
		
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			for (int t = 0; t < m; t++)
			{
				mapS[i][j] += (mapA[i][t] * mapB[t][j]);
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			cout << mapS[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}