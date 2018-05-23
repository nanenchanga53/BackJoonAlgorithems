#include<iostream>
using namespace std;
int main()
{
	int mymap[15][15] = { 0, };
	int T, i, j;
	cin >> T;

	for (i = 1; i <= 14; i++)
		mymap[0][i] = i;

	for (i = 1; i <= 14; i++)
	{
		mymap[i][1] = 1;
		for (j = 2; j <= 14; j++)
			mymap[i][j] = mymap[i - 1][j] + mymap[i][j - 1];
	}

	for (int t = 0; t < T; t++)
	{
		int k, n;
		cin >> k >> n;
		cout << mymap[k][n] << endl;
	}
	system("pause");
	return 0;
}